/*
 * exiv2-exifthumb.cpp
 *
 * Author(s):
 *	Stephane Delcroix  (stephane@delcroix.org)
 *
 * Copyright (c) 2008 Novell
 *
 * 
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 * 
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
 * LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
 * OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
 * WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 */
#include "exiv2-exifthumb.h"
#include "exiv2-exifthumb-private.h"
#include "exiv2-databuf-private.h"
#include <exiv2/exif.hpp>

G_BEGIN_DECLS

G_DEFINE_TYPE (Exiv2ExifThumb, exiv2_exifthumb, G_TYPE_OBJECT);

static void
exiv2_exifthumb_init (Exiv2ExifThumb *self)
{
	Exiv2ExifThumbPrivate *priv;
	self->priv = priv = EXIV2_EXIFTHUMB_GET_PRIVATE (self);
}

static void
exiv2_exifthumb_class_init (Exiv2ExifThumbClass *klass)
{
	g_type_class_add_private (klass, sizeof	(Exiv2ExifThumbPrivate));
}

const char*
exiv2_exifthumb_get_mimeType (Exiv2ExifThumb *self)
{
	g_return_val_if_fail (EXIV2_IS_EXIFTHUMB (self), NULL);
	return self->priv->thumb->mimeType ();
}

const char*
exiv2_exifthumb_get_extension (Exiv2ExifThumb *self)
{
	g_return_val_if_fail (EXIV2_IS_EXIFTHUMB (self), NULL);
	return self->priv->thumb->extension ();
}

glong
exiv2_exifthumb_writeFile (Exiv2ExifThumb *self, const char* path)
{
	g_return_val_if_fail (EXIV2_IS_EXIFTHUMB (self), NULL);
	return self->priv->thumb->writeFile (path);	
}

Exiv2DataBuf*
exiv2_exifthumb_copy (Exiv2ExifThumb *self)
{
	g_return_val_if_fail (EXIV2_IS_DATABUF (self), NULL);

	Exiv2DataBuf *databuf;
	databuf = EXIV2_DATABUF (g_object_new (EXIV2_TYPE_DATABUF, NULL));
	databuf->priv->buf = self->priv->thumb->copy ();

	return databuf;	
}

G_END_DECLS
