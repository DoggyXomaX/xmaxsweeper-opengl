#ifndef __OOP_H__
#define __OOP_H__

#include <stdlib.h>

#define nullptr NULL

#define class(class_name, init_parameters, struct_body) \
  int class_name##_Init init_parameters ;               \
  void class_name##_Destroy(void);                      \
  typedef struct {                                      \
    struct_body                                         \
  } class_name##_object

#define object(class_name) \
  class_name##_object *class_name = nullptr

#define new(class_name) \
  class_name = (class_name##_object*)malloc(sizeof(class_name##_object))

#define public(class_name, output_type, method) \
  output_type class_name##_##method

#define private(class_name, output_type, method) \
  output_type class_name##_##method

#define context(class_name) \
  class_name##_object *this = class_name

#define callback(name, output_type, parameters) \
  typedef output_type (*name) parameters

#define destroy(class_name) \
  if (class_name != nullptr)   \
    free(class_name)

#define func(class_name, method_name) \
  &(class_name##_##method_name)

#define invoke(class_name, method) \
  class_name##_##method

#define lengthof(param) \
  sizeof(param) / sizeof((param)[0])

#endif // __OOP_H__