
#ifndef vtkSMMyBoundsDomain_h
#define vtkSMMyBoundsDomain_h

#include "vtkSMBoundsDomain.h"

/// useless but just showing we can do it
class vtkSMMyBoundsDomain : public vtkSMBoundsDomain
{
public:
  static vtkSMMyBoundsDomain* New();
  vtkTypeMacro(vtkSMMyBoundsDomain, vtkSMBoundsDomain);
  void PrintSelf(ostream& os, vtkIndent indent);

  // overload setting of default values so we can orient them
  // our way
  void Update(vtkSMProperty* prop);

protected:
  vtkSMMyBoundsDomain();
  ~vtkSMMyBoundsDomain();
};

#endif // vtkSMMyBoundsDomain_h
