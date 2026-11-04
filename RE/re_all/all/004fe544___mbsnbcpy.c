
/* Library Function - Single Match
    __mbsnbcpy
   
   Library: Visual Studio 2003 Release */

uchar * __cdecl __mbsnbcpy(uchar *_Dest,uchar *_Source,size_t _Count)

{
  byte bVar1;
  byte bVar2;
  _ptiddata p_Var3;
  pthreadmbcinfo ptVar4;
  uint uVar5;
  uint uVar6;
  byte *pbVar7;
  byte *pbVar8;
  
  p_Var3 = __getptd();
  ptVar4 = p_Var3->_tpxcptinfoptrs;
  if (ptVar4 != DAT_00f488fc) {
    ptVar4 = ___updatetmbcinfo();
  }
  if (ptVar4->ismbcodepage == 0) {
    _Dest = (uchar *)_strncpy((char *)_Dest,(char *)_Source,_Count);
  }
  else if (_Count != 0) {
    pbVar7 = _Dest;
    do {
      bVar1 = *_Source;
      uVar5 = _Count - 1;
      bVar2 = ptVar4->mbctype[bVar1 + 5];
      *pbVar7 = bVar1;
      if ((bVar2 & 4) == 0) {
        pbVar8 = pbVar7 + 1;
        _Source = _Source + 1;
        if (bVar1 == 0) {
LAB_004fe5a9:
          if (uVar5 != 0) {
            for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
              pbVar8[0] = 0;
              pbVar8[1] = 0;
              pbVar8[2] = 0;
              pbVar8[3] = 0;
              pbVar8 = pbVar8 + 4;
            }
            for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
              *pbVar8 = 0;
              pbVar8 = pbVar8 + 1;
            }
          }
          break;
        }
      }
      else {
        if (uVar5 == 0) {
          *pbVar7 = 0;
          break;
        }
        bVar1 = _Source[1];
        uVar5 = _Count - 2;
        pbVar7[1] = bVar1;
        pbVar8 = pbVar7 + 2;
        _Source = _Source + 2;
        if (bVar1 == 0) {
          *pbVar7 = 0;
          goto LAB_004fe5a9;
        }
      }
      _Count = uVar5;
      pbVar7 = pbVar8;
    } while (uVar5 != 0);
  }
  return _Dest;
}

