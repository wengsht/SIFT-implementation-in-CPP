// =====================================================================================
// 
//       Filename:  SiftMatcher.h
// 
//    Description:  
// 
//        Version:  0.01
//        Created:  2014/11/23 15时27分36秒
//       Revision:  none
//       Compiler:  clang 3.5
// 
//         Author:  wengsht (SYSU-CMU), wengsht.sysu@gmail.com
//        Company:  
// 
// =====================================================================================
#ifndef _AUTOGUARD_SiftMatcher_H_
#define _AUTOGUARD_SiftMatcher_H_

#include "kdTree.h"
#include "feature.h"
#include <vector>
#include "ImageSet.h"


namespace bio {

/**  
 * \brief This is a class to match a feature point into a set of features ! (typically find the nearest feature point)
 *
 *  */
class SiftMatcher {
    public:
        SiftMatcher();
        ~SiftMatcher();

        /**
         * \brief setup KDTree
         *
         * */
        void setup();
        void loadDir(const char *dirName);
        void loadFile(const char *fileName);
        void loadFeatures(std::vector<Feature> & inputFeat);


        /**
         * \brief match a input point, return the nearest point in "database"
         * \param[in] features "datebase"
         *
         * */
        std::pair<Feature *, Feature *> match(Feature & input);
        unsigned long match(vector<Feature> &inputFeats);

        void dumpDot(std::ostream &dotOut);

        /**
         * \brief 
         *
         * */
        std::vector< Feature > & getFeatures();

        bool isGoodMatch(std::pair<Feature *, Feature *> matchs, Feature &inputFeat);

        void setMatchRatio(double ratio);
        void setMatchThres(double thres);
        /**
         * \brief set backtrack ratio of kd-tree
         * \param[in] it will search for number(features) / ratio times on the kd-tree, lower ratio means higher accuracy and lower speed
         *
         * */
        void setKdBackTrackRatio(int ratio);

    private:
        double matchRatio;
        double matchThres;
        ImageSet images;

        KDTree kdTree;
};
}

#endif

