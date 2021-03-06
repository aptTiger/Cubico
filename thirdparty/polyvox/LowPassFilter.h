/*******************************************************************************
* The MIT License (MIT)
*
* Copyright (c) 2015 David Williams and Matthew Williams
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in all
* copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*******************************************************************************/

#ifndef __PolyVox_LowPassFilter_H__
#define __PolyVox_LowPassFilter_H__

#include "Impl/IteratorController.h"

#include "Region.h"

namespace PolyVox
{
	/// This class is able to copy volume data from a source volume to a destination volume while performing low-pass filtering (blurring).
	template< typename SrcVolumeType, typename DstVolumeType, typename AccumulationType>
	class LowPassFilter
	{
	public:
		LowPassFilter(SrcVolumeType* pVolSrc, Region regSrc, DstVolumeType* pVolDst, Region regDst, uint32_t uKernelSize);

		/// Execute a standard approach to filtering which performs a number of neighbourhood look-ups per voxel.
		void execute();
		/// Execute a version with 'Summed Area Tables'. This should be faster for large kernel sizes but this hasn't really been confirmed yet.
		void executeSAT();

	private:
		//Source data
		SrcVolumeType* m_pVolSrc;
		Region m_regSrc;

		//Destination data
		DstVolumeType* m_pVolDst;
		Region m_regDst;

		//Kernel size
		uint32_t m_uKernelSize;
	};

}//namespace PolyVox

#endif //__PolyVox_LowPassFilter_H__

