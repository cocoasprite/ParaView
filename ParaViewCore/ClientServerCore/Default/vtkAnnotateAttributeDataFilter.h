/*=========================================================================

  Program:   ParaView
  Module:    vtkAnnotateAttributeDataFilter.h

  Copyright (c) Kitware, Inc.
  All rights reserved.
  See Copyright.txt or http://www.paraview.org/HTML/Copyright.html for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
/**
 * @class   vtkAnnotateAttributeDataFilter
 * @brief   specialization of
 * vtkPythonAnnotationFilter to work with element data.
 *
 * vtkAnnotateAttributeDataFilter is a specialization of
 * vtkPythonAnnotationFilter which makes it easier to annotate using data values
 * from any input dataset.
*/

#ifndef vtkAnnotateAttributeDataFilter_h
#define vtkAnnotateAttributeDataFilter_h

#include "vtkPVClientServerCoreDefaultModule.h" //needed for exports
#include "vtkPythonAnnotationFilter.h"

class VTKPVCLIENTSERVERCOREDEFAULT_EXPORT vtkAnnotateAttributeDataFilter
  : public vtkPythonAnnotationFilter
{
public:
  static vtkAnnotateAttributeDataFilter* New();
  vtkTypeMacro(vtkAnnotateAttributeDataFilter, vtkPythonAnnotationFilter);
  void PrintSelf(ostream& os, vtkIndent indent);

  //@{
  /**
   * Set the attribute array name to annotate with.
   */
  vtkSetStringMacro(ArrayName);
  vtkGetStringMacro(ArrayName);
  //@}

  //@{
  /**
   * Set the element number to annotate with.
   */
  vtkSetMacro(ElementId, vtkIdType);
  vtkGetMacro(ElementId, vtkIdType);
  //@}

  //@{
  /**
   * Set the rank to extract the data from.
   * Default is 0.
   */
  vtkSetMacro(ProcessId, int);
  vtkGetMacro(ProcessId, int);
  //@}

  //@{
  /**
   * Set the text prefix to display in front of the Field value
   */
  vtkSetStringMacro(Prefix);
  vtkGetStringMacro(Prefix);
  //@}

protected:
  vtkAnnotateAttributeDataFilter();
  ~vtkAnnotateAttributeDataFilter();

  virtual void EvaluateExpression();

  char* ArrayName;
  char* Prefix;
  int ProcessId;
  vtkIdType ElementId;

private:
  vtkAnnotateAttributeDataFilter(const vtkAnnotateAttributeDataFilter&) VTK_DELETE_FUNCTION;
  void operator=(const vtkAnnotateAttributeDataFilter&) VTK_DELETE_FUNCTION;
};

#endif
