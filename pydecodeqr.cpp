/*
 * 2014 http://ferdinandsilva.com
 *
 * Decode QR code in image file using libdecodeqr (Python Extension in C++ Sample Code)
 * Warning!! I'm not a c++ expert
 *
 * Author:
 * Ferdinand Silva <ferdinandsilva@ferdinandsilva.com>
 * 
 */
#include <python2.7/Python.h>
#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <decodeqr.h>

static PyObject *PyDecodeQRError;

static PyObject *
pydecodeqr_decode(PyObject *self, PyObject *args){
    const char *command;
    const char *retValue;

    if (!PyArg_ParseTuple(args, "s", &command))
        return NULL;

    try {
        IplImage *src=cvLoadImage(command,1);
        QrDecoderHandle decoder=qr_decoder_open();
        short stat=qr_decoder_decode_image(decoder,src);

        QrCodeHeader header;
        if(qr_decoder_get_header(decoder,&header)){
            retValue=new char[header.byte_size+1];
            qr_decoder_get_body(decoder,(unsigned char *)retValue,header.byte_size+1);
        }

        qr_decoder_close(decoder);
        cvReleaseImage(&src);
    }catch(cv::Exception& e) {
        PyErr_SetString(PyDecodeQRError, "Cannot decode image");
        return NULL;
    }

    return Py_BuildValue("s", retValue);
}

static PyMethodDef PyDecodeQRMethods[] = {
    {"decode",  pydecodeqr_decode, METH_VARARGS, "Decode QR code image using libdecodeqr (Python Extension in C++ Sample Code)"}
 };

PyMODINIT_FUNC
initpydecodeqr(void){

    PyObject *m;

    m = Py_InitModule("pydecodeqr", PyDecodeQRMethods);
    if (m == NULL)
        return;

    PyDecodeQRError = PyErr_NewException("pydecodeqr.DecodeError", NULL, NULL);
    Py_INCREF(PyDecodeQRError);
    PyModule_AddObject(m, "DecodeError", PyDecodeQRError);

}