
/* Library Function - Single Match
    public: class std::locale::facet * __thiscall std::locale::facet::_Decref(void)
   
   Library: Visual Studio 2003 Debug */

facet * __thiscall std::locale::facet::_Decref(facet *this)

{
  int iVar1;
  
  FUN_0050d92b(0);
  if ((*(int *)(this + 4) != 0) && (*(int *)(this + 4) != -1)) {
    *(int *)(this + 4) = *(int *)(this + 4) + -1;
  }
  iVar1 = *(int *)(this + 4);
  FUN_0050d94e();
  return (facet *)((iVar1 != 0) - 1 & (uint)this);
}

