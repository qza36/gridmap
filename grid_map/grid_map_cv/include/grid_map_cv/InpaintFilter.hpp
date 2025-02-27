/*
 * InpaintFilter.hpp
 *
 *  Created on: May 6, 2017
 *      Author: Tanja Baumann, Peter Fankhauser
 *   Institute: ETH Zurich, ANYbotics
 */

#ifndef GRID_MAP_CV__INPAINTFILTER_HPP_
#define GRID_MAP_CV__INPAINTFILTER_HPP_

#include <filters/filter_base.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/photo.hpp>

#include <vector>
#include <string>

// OpenCV
#include "grid_map_cv/grid_map_cv.hpp"

namespace grid_map
{

/*!
 * Uses OpenCV function to inpaint/fill holes in the input layer.
 */
template<typename T>
class InpaintFilter : public filters::FilterBase<T>
{
public:
  /*!
   * Constructor
   */
  InpaintFilter();

  /*!
   * Destructor.
   */
  virtual ~InpaintFilter();

  /*!
   * Configures the filter from parameters on the Parameter Server
   */
  virtual bool configure();

  /*!
   * Adds a new output layer to the map.
   * Uses the OpenCV function inpaint holes in the input layer.
   * Saves to filled map in the outputlayer.
   * @param mapIn grid map containing input layer
   * @param mapOut grid map containing mapIn and inpainted input layer.
   */
  virtual bool update(const T & mapIn, T & mapOut);

private:
  //! Inpainting radius.
  double radius_;

  //! Input layer name.
  std::string inputLayer_;

  //! Output layer name.
  std::string outputLayer_;
};

}  // namespace grid_map
#endif  // GRID_MAP_CV__INPAINTFILTER_HPP_
