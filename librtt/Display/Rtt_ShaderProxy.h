//////////////////////////////////////////////////////////////////////////////
//
// Copyright (C) 2018 Corona Labs Inc.
// Contact: support@coronalabs.com
//
// This file is part of the Corona game engine.
//
// Commercial License Usage
// Licensees holding valid commercial Corona licenses may use this file in
// accordance with the commercial license agreement between you and 
// Corona Labs Inc. For licensing terms and conditions please contact
// support@coronalabs.com or visit https://coronalabs.com/com-license
//
// GNU General Public License Usage
// Alternatively, this file may be used under the terms of the GNU General
// Public license version 3. The license is as published by the Free Software
// Foundation and appearing in the file LICENSE.GPL3 included in the packaging
// of this file. Please review the following information to ensure the GNU 
// General Public License requirements will
// be met: https://www.gnu.org/licenses/gpl-3.0.html
//
// For overview and more information on licensing please refer to README.md
//
//////////////////////////////////////////////////////////////////////////////

#ifndef _Rtt_ShaderProxy_H__
#define _Rtt_ShaderProxy_H__

#include "Display/Rtt_Shader.h"
#include "Core/Rtt_SharedPtr.h"
#include "Renderer/Rtt_RenderData.h"

// ----------------------------------------------------------------------------

namespace Rtt
{

// ----------------------------------------------------------------------------
class ShaderProxy : public Shader
{
public:
	ShaderProxy();
	virtual ~ShaderProxy();
	
public:
	void SetShader(SharedPtr<Shader> inputShader);
	void SetInput(int inputChannel, SharedPtr<Shader> shader);

	//Treat as protected
	virtual void Log(std::string preprend, bool last);
	virtual void SetTextureBounds( const TextureInfo& textureInfo );
	virtual bool HasChildren();
	virtual void UpdateCache( const TextureInfo& textureInfo, const RenderData& objectData );
	virtual Texture *GetTexture() const;
	virtual void RenderToTexture( Renderer& renderer, Geometry& cache ) const;
	
private:
	Shader *GetRawPtr();
	Shader *GetRawPtr() const;
	
private:
	SharedPtr<Shader> fInputShader;
	
};

// ----------------------------------------------------------------------------

} // namespace Rtt

// ----------------------------------------------------------------------------

#endif // _Rtt_ShaderProxy_H__
