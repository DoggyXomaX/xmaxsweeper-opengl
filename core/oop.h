#ifndef __OOP_H__
#define __OOP_H__

#define $CLASS(class_name, init_parameters, struct_body) \
  int class_name##_Init init_parameters ;                \
  void class_name##_Destroy(void);                       \
  typedef struct {                                       \
    struct_body                                          \
  } class_name##_private

#define $PUBLIC(output_type, class_name, method_name, parameters) \
  output_type class_name##_##method_name parameters

#endif // __OOP_H__