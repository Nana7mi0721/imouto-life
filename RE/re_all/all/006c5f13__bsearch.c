
/* Library Function - Single Match
    _bsearch
   
   Library: Visual Studio 2003 Release */

void * __cdecl
_bsearch(void *_Key,void *_Base,size_t _NumOfElements,size_t _SizeOfElements,
        _PtFuncCompare *_PtFuncCompare)

{
  uint uVar1;
  void *pvVar2;
  int iVar3;
  uint uVar4;
  void *pvVar5;
  
  pvVar5 = (void *)((_NumOfElements - 1) * _SizeOfElements + (int)_Base);
  if (_Base <= pvVar5) {
    do {
      uVar4 = _NumOfElements >> 1;
      if (uVar4 == 0) {
        if (_NumOfElements == 0) {
          return (void *)0x0;
        }
        iVar3 = (*_PtFuncCompare)(_Key,_Base);
        return (void *)(~-(uint)(iVar3 != 0) & (uint)_Base);
      }
      uVar1 = uVar4;
      if ((_NumOfElements & 1) == 0) {
        uVar1 = uVar4 - 1;
      }
      pvVar2 = (void *)(uVar1 * _SizeOfElements + (int)_Base);
      iVar3 = (*_PtFuncCompare)(_Key,pvVar2);
      if (iVar3 == 0) {
        return pvVar2;
      }
      if (iVar3 < 0) {
        pvVar5 = (void *)((int)pvVar2 - _SizeOfElements);
        if ((_NumOfElements & 1) == 0) {
          uVar4 = uVar4 - 1;
        }
      }
      else {
        _Base = (void *)((int)pvVar2 + _SizeOfElements);
      }
      _NumOfElements = uVar4;
    } while (_Base <= pvVar5);
  }
  return (void *)0x0;
}

