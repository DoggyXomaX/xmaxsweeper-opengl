#ifndef __OOP_H__
#define __OOP_H__

#define class(class_name, init_parameters, struct_body) \
  int class_name##_Init init_parameters ;                \
  void class_name##_Destroy(void);                       \
  typedef struct {                                       \
    struct_body                                          \
  } class_name##_private

#define object(class_name) \
  class_name##_private *class_name = NULL

#define new(class_name) \
  class_name = (class_name##_private*)malloc(sizeof(class_name##_private))

#define public(class_name, output_type, method_name, parameters) \
  output_type class_name##_##method_name parameters

#define private(class_name, output_type, method_name, parameters) \
  output_type class_name##_##method_name parameters

#define callback(name, output_type, parameters) \
  typedef output_type (*name) parameters

#define destroy(class_name) \
  free(class_name)

#endif // __OOP_H__