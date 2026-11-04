
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* Library Function - Single Match
    __setlocale_set_cat
   
   Library: Visual Studio 2003 Release */

undefined4 __setlocale_set_cat(undefined4 param_1)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  size_t sVar4;
  undefined4 uVar5;
  int *piVar6;
  BOOL BVar7;
  uint uVar8;
  int unaff_ESI;
  undefined1 local_1c4 [8];
  int local_1bc;
  uint local_1b4;
  ushort local_1b0 [6];
  int local_1a4;
  LPWORD local_1a0;
  void *local_19c;
  undefined *local_198;
  LPWORD local_194;
  undefined *local_190;
  undefined1 local_18c;
  byte abStack_18b [255];
  char local_8c [132];
  undefined4 local_8;
  
  local_8 = DAT_0084b484;
  iVar3 = __expandlocale(param_1,local_8c,local_1b0,&local_194);
  uVar5 = 0;
  if (iVar3 != 0) {
    iVar3 = _strcmp(local_8c,(char *)(&DAT_0084b66c)[unaff_ESI * 3]);
    if (iVar3 == 0) {
      uVar5 = (&DAT_0084b66c)[unaff_ESI * 3];
    }
    else {
      sVar4 = _strlen(local_8c);
      local_19c = _malloc(sVar4 + 1);
      uVar5 = 0;
      if (local_19c != (void *)0x0) {
        local_198 = (undefined *)(&DAT_0084b66c)[unaff_ESI * 3];
        puVar1 = &DAT_00a1fdf8 + unaff_ESI;
        local_1b4 = *puVar1;
        local_190 = &DAT_00a1fe1c + unaff_ESI * 6;
        _memcpy(local_1c4,local_190,6);
        local_1a0 = DAT_00a1fe10;
        uVar5 = FUN_004fd700(local_19c,local_8c);
        (&DAT_0084b66c)[unaff_ESI * 3] = uVar5;
        *puVar1 = (uint)local_1b0[0];
        _memcpy(local_190,local_1b0,6);
        if (unaff_ESI == 2) {
          local_190 = (undefined *)0x0;
          DAT_00a1fe10 = local_194;
          local_1a4 = DAT_0084b554;
          piVar6 = (int *)&DAT_0084b530;
          iVar3 = DAT_0084b550;
          do {
            if (local_194 == (LPWORD)*piVar6) {
              if (local_190 != (undefined *)0x0) {
                DAT_0084b530 = (&DAT_0084b530)[(int)local_190 * 2];
                DAT_0084b534 = (&DAT_0084b534)[(int)local_190 * 2];
                (&DAT_0084b530)[(int)local_190 * 2] = (LPWORD)iVar3;
                (&DAT_0084b534)[(int)local_190 * 2] = local_1a4;
              }
              break;
            }
            local_1bc = *piVar6;
            local_190 = local_190 + 1;
            *piVar6 = iVar3;
            iVar2 = piVar6[1];
            piVar6[1] = local_1a4;
            piVar6 = piVar6 + 2;
            iVar3 = local_1bc;
            local_1a4 = iVar2;
          } while ((int)piVar6 < 0x84b558);
          if (local_190 == (undefined *)0x5) {
            BVar7 = ___crtGetStringTypeA
                              ((_locale_t)0x1,0x7d2520,(LPCSTR)0x7f,(int)&local_18c,local_194,
                               DAT_00a1fe00,1);
            if (BVar7 == 0) {
              DAT_0084b534 = 0;
            }
            else {
              uVar8 = 0;
              do {
                abStack_18b[uVar8 * 2] = abStack_18b[uVar8 * 2] & 1;
                uVar8 = uVar8 + 1;
              } while (uVar8 < 0x7f);
              iVar3 = _memcmp(&local_18c,&DAT_007d2420,0xfe);
              DAT_0084b534 = (uint)(iVar3 == 0);
            }
            DAT_0084b530 = DAT_00a1fe10;
          }
          DAT_0084be50 = DAT_0084b534;
        }
        if (unaff_ESI == 1) {
          DAT_00a1fe14 = local_194;
        }
        iVar3 = (**(code **)(&DAT_0084b670 + unaff_ESI * 0xc))();
        if (iVar3 == 0) {
          if (local_198 != &DAT_0084b4d0) {
            _free(local_198);
          }
          uVar5 = (&DAT_0084b66c)[unaff_ESI * 3];
        }
        else {
          (&DAT_0084b66c)[unaff_ESI * 3] = local_198;
          _free(local_19c);
          *puVar1 = local_1b4;
          DAT_00a1fe10 = local_1a0;
          uVar5 = 0;
        }
      }
    }
  }
  return uVar5;
}

