
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    ___init_numeric
   
   Library: Visual Studio 2003 Release */

int __cdecl ___init_numeric(threadlocinfo *_LocInfo)

{
  char *pcVar1;
  char cVar2;
  int *_Memory;
  int iVar3;
  int iVar4;
  char *pcVar5;
  int iVar6;
  undefined **_Memory_00;
  undefined4 *puVar7;
  uint _Lc_type;
  char *pcVar8;
  void *unaff_EDI;
  undefined **ppuVar9;
  void *_Address;
  void *_Address_00;
  
  if ((DAT_00a1fe08 == 0) && (DAT_00a1fe04 == 0)) {
    if (((DAT_00f488f0 != (int *)0x0) && (*DAT_00f488f0 == 0)) &&
       (DAT_00f488f0 != *(int **)(PTR_DAT_0084b52c + 0x2c))) {
      _free(DAT_00f488f0);
      _free(DAT_00a1fdd0);
    }
    DAT_00f488f4 = (undefined4 *)0x0;
    DAT_00f488f0 = (int *)0x0;
    _Memory_00 = &PTR_DAT_0084be14;
    DAT_00a1fdd0 = (undefined **)0x0;
LAB_005051cc:
    DAT_0084be64 = **_Memory_00;
    _DAT_0084be68 = 1;
    iVar6 = 0;
    PTR_PTR_0084be44 = (undefined *)_Memory_00;
  }
  else {
    _Memory_00 = _calloc(1,0x30);
    if (_Memory_00 != (undefined **)0x0) {
      puVar7 = (undefined4 *)PTR_PTR_0084be44;
      ppuVar9 = _Memory_00;
      for (iVar6 = 0xc; iVar6 != 0; iVar6 = iVar6 + -1) {
        *ppuVar9 = (undefined *)*puVar7;
        puVar7 = puVar7 + 1;
        ppuVar9 = ppuVar9 + 1;
      }
      _Memory = _malloc(4);
      if (_Memory != (int *)0x0) {
        *_Memory = 0;
        if (DAT_00a1fe08 == 0) {
          DAT_00f488f4 = (undefined4 *)0x0;
          *_Memory_00 = PTR_DAT_0084be14;
          _Memory_00[1] = PTR_DAT_0084be18;
          _Memory_00[2] = PTR_DAT_0084be1c;
        }
        else {
          DAT_00f488f4 = _malloc(4);
          if (DAT_00f488f4 == (undefined4 *)0x0) {
            iVar6 = 1;
LAB_0050512a:
            _free(_Memory_00);
            _free(_Memory);
            return iVar6;
          }
          *DAT_00f488f4 = 0;
          _Lc_type = (uint)DAT_00a1fe36;
          _Address_00 = (void *)0x1;
          iVar6 = ___getlocaleinfo((_locale_t)0x1,_Lc_type,(LPCWSTR)0xe,(LCTYPE)_Memory_00,unaff_EDI
                                  );
          _Address = (void *)0x1;
          iVar3 = ___getlocaleinfo((_locale_t)0x1,_Lc_type,(LPCWSTR)0xf,(LCTYPE)(_Memory_00 + 1),
                                   _Address_00);
          iVar4 = ___getlocaleinfo((_locale_t)0x1,_Lc_type,(LPCWSTR)0x10,(LCTYPE)(_Memory_00 + 2),
                                   _Address);
          if (iVar4 != 0 || (iVar6 != 0 || iVar3 != 0)) {
            ___free_lconv_num(_Memory_00);
            iVar6 = -1;
            goto LAB_0050512a;
          }
          pcVar5 = _Memory_00[2];
          while (*pcVar5 != '\0') {
            cVar2 = *pcVar5;
            if ((cVar2 < '0') || ('9' < cVar2)) {
              if (cVar2 != ';') goto LAB_00505156;
              pcVar8 = pcVar5;
              do {
                pcVar1 = pcVar8 + 1;
                *pcVar8 = *pcVar1;
                pcVar8 = pcVar1;
              } while (*pcVar1 != '\0');
            }
            else {
              *pcVar5 = cVar2 + -0x30;
LAB_00505156:
              pcVar5 = pcVar5 + 1;
            }
          }
        }
        if (((DAT_00f488f0 != (int *)0x0) && (*DAT_00f488f0 == 0)) &&
           (DAT_00f488f0 != *(int **)(PTR_DAT_0084b52c + 0x2c))) {
          _free(DAT_00f488f0);
          _free(DAT_00a1fdd0);
        }
        DAT_00a1fdd0 = _Memory_00;
        DAT_00f488f0 = _Memory;
        goto LAB_005051cc;
      }
      _free(_Memory_00);
    }
    iVar6 = 1;
  }
  return iVar6;
}

