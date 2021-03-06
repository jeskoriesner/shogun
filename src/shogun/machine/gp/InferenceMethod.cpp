/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * Written (W) 2013 Roman Votyakov
 * Copyright (C) 2012 Jacob Walker
 * Copyright (C) 2013 Roman Votyakov
 */

#include <shogun/machine/gp/InferenceMethod.h>

using namespace shogun;

CInferenceMethod::CInferenceMethod()
{
	init();
}

CInferenceMethod::CInferenceMethod(CKernel* kern, CFeatures* feat,
		CMeanFunction* m, CLabels* lab, CLikelihoodModel* mod)
{
	init();

	set_kernel(kern);
	set_features(feat);
	set_labels(lab);
	set_model(mod);
	set_mean(m);
}

CInferenceMethod::~CInferenceMethod()
{
	SG_UNREF(m_kernel);
	SG_UNREF(m_features);
	SG_UNREF(m_labels);
	SG_UNREF(m_model);
	SG_UNREF(m_mean);
}

void CInferenceMethod::init()
{
	SG_ADD((CSGObject**)&m_kernel, "kernel", "Kernel", MS_AVAILABLE);
	SG_ADD(&m_scale, "scale", "Kernel Scale", MS_AVAILABLE);
	SG_ADD((CSGObject**)&m_model, "likelihood_model", "Likelihood model",
			MS_AVAILABLE);
	SG_ADD((CSGObject**)&m_labels, "labels", "Labels", MS_NOT_AVAILABLE);
	SG_ADD((CSGObject**)&m_features, "features", "Features", MS_NOT_AVAILABLE);
	SG_ADD((CSGObject**)&m_mean, "mean_function", "Mean Function", MS_NOT_AVAILABLE);

	m_kernel=NULL;
	m_model=NULL;
	m_labels=NULL;
	m_features=NULL;
	m_mean=NULL;
	m_scale=1.0;
}

void CInferenceMethod::set_features(CFeatures* feat)
{
	SG_REF(feat);
	SG_UNREF(m_features);
	m_features=feat;
}

void CInferenceMethod::set_kernel(CKernel* kern)
{
	SG_REF(kern);
	SG_UNREF(m_kernel);
	m_kernel=kern;
}

void CInferenceMethod::set_mean(CMeanFunction* m)
{
	SG_REF(m);
	SG_UNREF(m_mean);
	m_mean=m;
}

void CInferenceMethod::set_labels(CLabels* lab)
{
	SG_REF(lab);
	SG_UNREF(m_labels);
	m_labels=lab;
}

void CInferenceMethod::set_model(CLikelihoodModel* mod)
{
	SG_REF(mod);
	SG_UNREF(m_model);
	m_model=mod;
}

void CInferenceMethod::set_scale(float64_t s)
{
	m_scale=s;
}
