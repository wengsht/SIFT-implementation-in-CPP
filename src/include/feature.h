#ifndef _AUTOGUARD_Feature_H_
#define _AUTOGUARD_Feature_H_

#include "define.h"
#include "configure.h"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>

namespace bio {

template<class Type>
class point {
public:
    Type x, y; /*!< Point coordinates<x,y> */
               /* !< Detailed description after the member */ 
    point() {} 
    point(Type x, Type y) : x(x), y(y) {}
};

class Meta {
public:
    int octIdx;
    int layerIdx;

    cv::Mat * img;
    point<int> location;

    /* scale */
    double scale;

    double globalScale;
};

class Feature {
public:
    friend class SiftExtractor;
    void  copyFeature(Feature& feature, Feature& newFeature);

    /**
     * \brief dump feature's info
     * \param[in] Out output stream
     *
     * */
    void dump(std::ostream & Out);

    /**
     * \brief return length of descriptor
     *
     * */
    int size() const;

    /**
     * \brief return idx-th descriptor
     *
     * */
    double & operator [] (int idx);

    /**
     * \brief return idx-th descriptor
     *
     * */
    const double & operator [] (int idx) const;

    /**
     *
     * \brief Euclidean Distance of two feature
     * \return Euclidean Distance
     *
     * */
    double operator - (const Feature & b);

    /**
     *
     * \brief Set container
     *
     * */
    void setContrainer(void *container, unsigned long hashTag = -1);
    /**
     *
     * \brief Get container
     *      Get container of this feature, typically to get the image 
     * */
    void *getContainer();

    /**
     *
     * \brief Get hash tag
     *      Get hash tag of this feature, same object should have the same tag
     * */
    unsigned long getHashTag();

    /**
     *
     * \brief Check if two feature come from the same object
     *
     * */
    bool sameHashTag(Feature &b);

    /**
     *
     * \brief 
     * */
    void load(std::istream & IN);

    /**
     *
     * \brief 
     * */
    void store(std::ostream & OUT);

    static int descriptor_length;
    /* Location in the image */

    /* Location in original image */
    point<double> originLoc;

    /*  orientation */
    double orient;

    double descriptor[DEFAULT_DESCR_LEN];

    Meta * meta;

    void * container; ///< Use to get object/image containing this feature
    unsigned long hashTag; ///< Image feature from the same object should have the same hashTag
};
}

#endif

