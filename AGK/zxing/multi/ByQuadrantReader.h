#ifndef __BY_QUADRANT_READER_H__
#define __BY_QUADRANT_READER_H__

/*
 *  Copyright 2011 ZXing authors All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <Reader.h>
#include <BinaryBitmap.h>
#include <Result.h>
#include <DecodeHints.h>

namespace zxing {
namespace multi {
class ByQuadrantReader : public Reader {
  private:
    Reader& delegate_;

  public:
    ByQuadrantReader(Reader& delegate);
    virtual ~ByQuadrantReader();
    virtual Ref<Result> decode(Ref<BinaryBitmap> image);
    virtual Ref<Result> decode(Ref<BinaryBitmap> image, DecodeHints hints);
};
} // End zxing::multi namespace
} // End zxing namespace

#endif // __BY_QUADRANT_READER_H__
