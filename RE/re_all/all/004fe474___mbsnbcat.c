
/* Library Function - Single Match
    __mbsnbcat
   
   Library: Visual Studio 2003 Release */

uchar * __cdecl __mbsnbcat(uchar *_Dest,uchar *_Source,size_t _Count)

{
  byte bVar1;
  byte bVar2;
  _ptiddata p_Var3;
  pthreadmbcinfo ptVar4;
  int iVar5;
  size_t sVar6;
  byte *pbVar7;
  byte *pbVar8;
  
  p_Var3 = __getptd();
  ptVar4 = p_Var3->_tpxcptinfoptrs;
  if (_Count != 0) {
    if (ptVar4 != DAT_00f488fc) {
      ptVar4 = ___updatetmbcinfo();
    }
    if (ptVar4->ismbcodepage == 0) {
      _Dest = (uchar *)_strncat((char *)_Dest,(char *)_Source,_Count);
    }
    else {
      pbVar8 = _Dest;
      do {
        pbVar7 = pbVar8;
        pbVar8 = pbVar7 + 1;
      } while (*pbVar7 != 0);
      iVar5 = ___mbsbtype_mt(ptVar4,_Dest,pbVar7 + (-1 - (int)_Dest));
      if (iVar5 == 1) {
        pbVar7 = pbVar7 + -1;
      }
      do {
        bVar1 = *_Source;
        sVar6 = _Count - 1;
        bVar2 = ptVar4->mbctype[bVar1 + 5];
        *pbVar7 = bVar1;
        if ((bVar2 & 4) == 0) {
          pbVar8 = pbVar7 + 1;
          _Source = _Source + 1;
          if (bVar1 == 0) break;
        }
        else {
          pbVar8 = pbVar7 + 1;
          if (sVar6 == 0) {
            *pbVar7 = 0;
            break;
          }
          bVar1 = _Source[1];
          *pbVar8 = bVar1;
          pbVar8 = pbVar7 + 2;
          _Source = _Source + 2;
          sVar6 = _Count - 2;
          if (bVar1 == 0) {
            *pbVar7 = 0;
            break;
          }
        }
        _Count = sVar6;
        pbVar7 = pbVar8;
      } while (sVar6 != 0);
      iVar5 = ___mbsbtype_mt(ptVar4,_Dest,pbVar8 + (-1 - (int)_Dest));
      if (iVar5 == 1) {
        pbVar8[-1] = 0;
      }
      else {
        *pbVar8 = 0;
      }
    }
  }
  return _Dest;
}

