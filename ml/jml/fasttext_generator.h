/* fasttext_tree_generator.h                                       -*- C++ -*-
   Mathieu Marquis Bolduc, 2 March 2027

   This file is part of MLDB. Copyright 2017 mldb.ai inc. All rights reserved.

   Generator for fasttext classification
*/

#pragma once

#include "classifier_generator.h"
#include "fasttext_classifier.h"

namespace ML {


/*****************************************************************************/
/* FastText_Generator                                                        */
/*****************************************************************************/

/** Class to generate a classifier.  The meta-algorithms (bagging, boosting,
    etc) can use this algorithm to generate weak-learners.
*/

class FastText_Generator : public Classifier_Generator {
public:
    FastText_Generator();

    virtual ~FastText_Generator();

    /** Configure the generator with its parameters. */
    virtual void
    configure(const Configuration & config,
              std::vector<std::string> & unparsedKeys) override;
    
    /** Return to the default configuration. */
    virtual void defaults() override;

    /** Return possible configuration options. */
    virtual Config_Options options() const override;

    /** Initialize the generator, given the feature space to be used for
        generation. */
    virtual void init(std::shared_ptr<const Feature_Space> fs,
                      Feature predicted) override;

    using Classifier_Generator::generate;

    /** Generate a classifier from one training set. */
    virtual std::shared_ptr<Classifier_Impl>
    generate(Thread_Context & context,
             const Training_Data & training_data,
             const distribution<float> & weights,
             const std::vector<Feature> & features,
             int recursion = 0) const;
    

    /* Once init has been called, we clone our potential models from this
       one. */
    FastTest_Classifier model;

    //Parameters:
    int epoch = 5;
    int dims = 100;
    int verbose = 0;
   
};

}