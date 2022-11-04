#ifndef __OOP_H__
#define __OOP_H__

#define $CLASS(class_name, init_parameters, struct_body) \
  int class_name##_Init init_parameters ;                \
  void class_name##_Destroy(void);                       \
  typedef struct {                                       \
    struct_body                                          \
  } class_name##_private

#define $OBJECT(class_name) \
  class_name##_private *class_name = NULL

#define $NEW(class_name) \
  class_name = (class_name##_private*)malloc(sizeof(class_name##_private))

#define $PUBLIC(output_type, class_name, method_name, parameters) \
  output_type class_name##_##method_name parameters

#define $PRIVATE(output_type, class_name, method_name, parameters) \
  output_type class_name##_##method_name parameters

#define $CALLBACK(name, output_type, parameters) \
  typedef output_type (*name) parameters

#define $DESTROY(class_name) \
  free(class_name)

#endif // __OOP_H__