
/* Library Function - Single Match
    ___init_monetary
   
   Library: Visual Studio 2003 Release */

int __cdecl ___init_monetary(threadlocinfo *_LocInfo)

{
  char *pcVar1;
  char cVar2;
  undefined4 *_Memory;
  undefined4 *_Memory_00;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  char *pcVar17;
  int iVar18;
  uint _Lc_type;
  char *pcVar19;
  undefined **ppuVar20;
  void *unaff_EDI;
  undefined4 *puVar21;
  void *pvVar22;
  void *pvVar23;
  
  if ((DAT_00a1fe04 == 0) && (DAT_00a1fe08 == 0)) {
    DAT_00f488ec = (undefined4 *)0x0;
    DAT_00f488f0 = (undefined4 *)0x0;
    PTR_PTR_0084be44 = (undefined *)&PTR_DAT_0084be14;
    DAT_00a1fdd0 = (undefined4 *)0x0;
LAB_005054fd:
    iVar18 = 0;
  }
  else {
    _Memory = _calloc(1,0x30);
    if (_Memory != (undefined4 *)0x0) {
      _Memory_00 = _malloc(4);
      if (_Memory_00 == (undefined4 *)0x0) {
        _free(_Memory);
      }
      else {
        *_Memory_00 = 0;
        if (DAT_00a1fe04 == 0) {
          ppuVar20 = &PTR_DAT_0084be14;
          puVar21 = _Memory;
          for (iVar18 = 0xc; iVar18 != 0; iVar18 = iVar18 + -1) {
            *puVar21 = *ppuVar20;
            ppuVar20 = ppuVar20 + 1;
            puVar21 = puVar21 + 1;
          }
          DAT_00f488ec = (undefined4 *)0x0;
LAB_005054ca:
          *_Memory = *(undefined4 *)PTR_PTR_0084be44;
          _Memory[1] = *(undefined4 *)(PTR_PTR_0084be44 + 4);
          _Memory[2] = *(undefined4 *)(PTR_PTR_0084be44 + 8);
          PTR_PTR_0084be44 = (undefined *)_Memory;
          DAT_00a1fdd0 = _Memory;
          DAT_00f488f0 = _Memory_00;
          goto LAB_005054fd;
        }
        DAT_00f488ec = _malloc(4);
        if (DAT_00f488ec == (undefined4 *)0x0) {
          _free(_Memory);
          _free(_Memory_00);
        }
        else {
          *DAT_00f488ec = 0;
          _Lc_type = (uint)DAT_00a1fe30;
          pvVar23 = (void *)0x1;
          iVar18 = ___getlocaleinfo((_locale_t)0x1,_Lc_type,(LPCWSTR)0x15,(LCTYPE)(_Memory + 3),
                                    unaff_EDI);
          pvVar22 = (void *)0x1;
          iVar3 = ___getlocaleinfo((_locale_t)0x1,_Lc_type,(LPCWSTR)0x14,(LCTYPE)(_Memory + 4),
                                   pvVar23);
          pvVar23 = (void *)0x1;
          iVar4 = ___getlocaleinfo((_locale_t)0x1,_Lc_type,(LPCWSTR)0x16,(LCTYPE)(_Memory + 5),
                                   pvVar22);
          iVar5 = ___getlocaleinfo((_locale_t)0x1,_Lc_type,(LPCWSTR)0x17,(LCTYPE)(_Memory + 6),
                                   pvVar23);
          pvVar23 = (void *)0x1;
          iVar6 = ___getlocaleinfo((_locale_t)0x1,_Lc_type,(LPCWSTR)0x18,(LCTYPE)(_Memory + 7),
                                   unaff_EDI);
          pvVar22 = (void *)0x1;
          iVar7 = ___getlocaleinfo((_locale_t)0x1,_Lc_type,(LPCWSTR)0x50,(LCTYPE)(_Memory + 8),
                                   pvVar23);
          pvVar23 = (void *)0x1;
          iVar8 = ___getlocaleinfo((_locale_t)0x1,_Lc_type,(LPCWSTR)0x51,(LCTYPE)(_Memory + 9),
                                   pvVar22);
          iVar9 = ___getlocaleinfo((_locale_t)0x0,_Lc_type,(LPCWSTR)0x1a,(LCTYPE)(_Memory + 10),
                                   pvVar23);
          pvVar23 = (void *)0x0;
          iVar10 = ___getlocaleinfo((_locale_t)0x0,_Lc_type,(LPCWSTR)0x19,(int)_Memory + 0x29,
                                    unaff_EDI);
          pvVar22 = (void *)0x0;
          iVar11 = ___getlocaleinfo((_locale_t)0x0,_Lc_type,(LPCWSTR)0x54,(int)_Memory + 0x2a,
                                    pvVar23);
          pvVar23 = (void *)0x0;
          iVar12 = ___getlocaleinfo((_locale_t)0x0,_Lc_type,(LPCWSTR)0x55,(int)_Memory + 0x2b,
                                    pvVar22);
          iVar13 = ___getlocaleinfo((_locale_t)0x0,_Lc_type,(LPCWSTR)0x56,(LCTYPE)(_Memory + 0xb),
                                    pvVar23);
          pvVar22 = (void *)0x0;
          iVar14 = ___getlocaleinfo((_locale_t)0x0,_Lc_type,(LPCWSTR)0x57,(int)_Memory + 0x2d,
                                    unaff_EDI);
          pvVar23 = (void *)0x0;
          iVar15 = ___getlocaleinfo((_locale_t)0x0,_Lc_type,(LPCWSTR)0x52,(int)_Memory + 0x2e,
                                    pvVar22);
          iVar16 = ___getlocaleinfo((_locale_t)0x0,_Lc_type,(LPCWSTR)0x53,(int)_Memory + 0x2f,
                                    pvVar23);
          if (iVar16 == 0 &&
              (((((((((((((iVar18 == 0 && iVar3 == 0) && iVar4 == 0) && iVar5 == 0) && iVar6 == 0)
                      && iVar7 == 0) && iVar8 == 0) && iVar9 == 0) && iVar10 == 0) && iVar11 == 0)
                 && iVar12 == 0) && iVar13 == 0) && iVar14 == 0) && iVar15 == 0)) {
            pcVar17 = (char *)_Memory[7];
            while (*pcVar17 != '\0') {
              cVar2 = *pcVar17;
              if ((cVar2 < '0') || ('9' < cVar2)) {
                if (cVar2 != ';') goto LAB_00505498;
                pcVar19 = pcVar17;
                do {
                  pcVar1 = pcVar19 + 1;
                  *pcVar19 = *pcVar1;
                  pcVar19 = pcVar1;
                } while (*pcVar1 != '\0');
              }
              else {
                *pcVar17 = cVar2 + -0x30;
LAB_00505498:
                pcVar17 = pcVar17 + 1;
              }
            }
            goto LAB_005054ca;
          }
          ___free_lconv_mon(_Memory);
          _free(_Memory);
          _free(_Memory_00);
        }
      }
    }
    iVar18 = 1;
  }
  return iVar18;
}

