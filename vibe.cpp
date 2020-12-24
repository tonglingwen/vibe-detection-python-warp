#include<iostream>
#include<cmath>
#include<boost/python/module.hpp>
#include<boost/python/def.hpp>
#include<boost/python/extract.hpp>
#include<boost/python/numpy.hpp>
#include<boost/python/list.hpp>
#include"vibe-background-sequential.h"
#include<stdlib.h>

using namespace std;
using namespace boost::python;
namespace np = boost::python::numpy;


int first=0;
int cols=0;
int rows=0;
boost::uint8_t* frame;
boost::uint8_t* segmentationMap;
vibeModel_Sequential_t *model;

void vibe_frame()
{
		if (first == 0) {
			first=1;
			model = (vibeModel_Sequential_t*)libvibeModel_Sequential_New();
			libvibeModel_Sequential_AllocInit_8u_C1R(model, frame, cols, rows);
		}
		/* ViBe: Segmentation and updating. */
		libvibeModel_Sequential_Segmentation_8u_C1R(model, frame, segmentationMap);
		libvibeModel_Sequential_Update_8u_C1R(model, frame, segmentationMap);
}

void initializevibe(int width,int height)
{
	first=0;
	cols=width;
	rows=height;
	segmentationMap=(boost::uint8_t*)malloc(cols*rows);
	frame=(boost::uint8_t*)malloc(cols*rows);
}

np::ndarray vibe(np::ndarray mat){
	memcpy(frame,mat.get_data(),cols*rows);
	vibe_frame();
	np::dtype dt1 = np::dtype::get_builtin<boost::uint8_t>();
	np::ndarray mul_data_ex = np::from_data(segmentationMap, dt1,
											make_tuple(mat.shape(0),mat.shape(1)),
											make_tuple(mat.strides(0),mat.strides(1)),
											object());
	return mul_data_ex.copy();
}

/* Define your module name within BOOST_PYTHON_MODULE */ 
BOOST_PYTHON_MODULE(vibe){ 
  /* Initialise numpy */
  np::initialize();
  
  def("initializevibe",initializevibe);
  def("vibe", vibe);
}
