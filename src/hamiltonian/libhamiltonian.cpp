#include <boost/python.hpp>
#include <boost/python/suite/indexing/vector_indexing_suite.hpp>

#include "libhamiltonian.h"

using namespace boost::python;
using namespace libhamiltonian;



void export_Hamiltonian_objects(){

  boost::python::list (*expt_SAC_Ham1)(double,boost::python::list) = &SAC_Ham;
  boost::python::list (*expt_DAC_Ham1)(double,boost::python::list) = &DAC_Ham;
  boost::python::list (*expt_ECWR_Ham1)(double,boost::python::list) = &ECWR_Ham;
  boost::python::list (*expt_Marcus_Ham1)(double,boost::python::list) = &Marcus_Ham;
  boost::python::list (*expt_SEXCH_Ham1)(double,boost::python::list) = &SEXCH_Ham;

  def("SAC_Ham", expt_SAC_Ham1);
  def("DAC_Ham", expt_DAC_Ham1);
  def("ECWR_Ham", expt_ECWR_Ham1);
  def("Marcus_Ham", expt_Marcus_Ham1);
  def("SEXCH_Ham", expt_SEXCH_Ham1);


  void (Hamiltonian_Model::*set_params1)(vector<double>&) = &Hamiltonian_Model::set_params;
  void (Hamiltonian_Model::*set_params2)(boost::python::list) = &Hamiltonian_Model::set_params;

  void (Hamiltonian_Model::*compute_diabatic1)(vector<double>&,vector<double>&) = &Hamiltonian_Model::compute_diabatic;
  void (Hamiltonian_Model::*compute_diabatic2)(boost::python::list,boost::python::list) = &Hamiltonian_Model::compute_diabatic;

  void (Hamiltonian_Model::*compute_adiabatic1)(vector<double>&,vector<double>&) = &Hamiltonian_Model::compute_adiabatic;
  void (Hamiltonian_Model::*compute_adiabatic2)(boost::python::list,boost::python::list) = &Hamiltonian_Model::compute_adiabatic;



  class_<Hamiltonian_Model>("Hamiltonian_Model",init<int>())
      .def("__copy__", &generic__copy__<Hamiltonian_Model>)
      .def("__deepcopy__", &generic__deepcopy__<Hamiltonian_Model>)
      //.def_readwrite("rb_torque_e",&RigidBody::rb_torque_e)

      .def("set_params", set_params2)
      .def("set_rep", &Hamiltonian_Model::set_rep)

      .def("compute_diabatic", compute_diabatic2 )
      .def("compute_adiabatic",compute_adiabatic2)

      .def("H", &Hamiltonian_Model::H)

  ;



}


#ifdef CYGWIN
BOOST_PYTHON_MODULE(cyghamiltonian){
#else
BOOST_PYTHON_MODULE(libhamiltonian){
#endif

  // Register converters:
  // See here: https://misspent.wordpress.com/2009/09/27/how-to-write-boost-python-converters/
  //to_python_converter<std::vector<DATA>, VecToList<DATA> >();

//  export_Mathematics_objects();
  export_Hamiltonian_objects();

}


