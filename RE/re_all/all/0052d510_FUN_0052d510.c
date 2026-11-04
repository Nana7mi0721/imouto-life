
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

undefined4 FUN_0052d510(ushort *param_1,short *param_2,int param_3,short *param_4)

{
  char cVar1;
  short sVar2;
  bool bVar3;
  ushort uVar4;
  ushort uVar5;
  undefined2 *puVar6;
  int iVar7;
  undefined4 uVar8;
  ushort uVar9;
  int iVar10;
  int iVar11;
  ushort *puStack_1820;
  int iStack_181c;
  int iStack_1814;
  uint uStack_1810;
  int iStack_180c;
  uint uStack_1808;
  int local_1804;
  ushort auStack_1800 [1536];
  short local_c00 [1534];
  undefined4 uStack_4;
  
  uStack_4 = 0x52d51a;
  iVar10 = 0;
  bVar3 = false;
  local_1804 = 0;
  if (param_4 == (short *)0x0) {
    if (PTR_FUN_0084c9f4 == (undefined *)0x0) {
      (*(code *)PTR_FUN_0084c9f0)(local_c00);
    }
    else {
      (*(code *)PTR_FUN_0084c9f4)(local_c00,0xc00);
    }
    param_4 = local_c00;
  }
  if (param_1 == (ushort *)0x0) {
    FUN_0056cf70(param_2,param_3,param_4);
    return 0;
  }
  uVar5 = *param_1;
  uStack_1808 = (uint)uVar5;
  puStack_1820 = (ushort *)0x0;
  iStack_1814 = 0;
  if (((uVar5 == 0x5c) && (param_1[1] == 0x5c)) || ((uVar5 == 0x2f && (param_1[1] == 0x2f)))) {
    param_2[1] = 0;
    *param_2 = 0x5c;
    puStack_1820 = (ushort *)0x2;
    bVar3 = true;
    iVar10 = 1;
  }
  else {
    iStack_181c = 0;
    if (DAT_00ddb2e8 < 1) {
      iVar7 = iStack_180c;
    }
    else {
      do {
        iVar7 = 0;
        if (uVar5 != 0) {
          iStack_180c = *(int *)(&DAT_00ddb2a8 + iStack_181c * 4);
          while (cVar1 = *(char *)(iStack_180c + iVar7), cVar1 != '\0') {
            uVar9 = param_1[iVar7];
            if ((uVar9 == 0x5c) || (uVar9 == 0x2f)) {
              uVar9 = 0x5c;
            }
            if ((cVar1 == '\\') || (cVar1 == '/')) {
              uVar4 = 0x5c;
            }
            else {
              uVar4 = (ushort)cVar1;
            }
            if ((uVar9 != uVar4) || (iVar7 = iVar7 + 1, param_1[iVar7] == 0)) break;
          }
        }
      } while ((*(char *)(iVar7 + *(int *)(&DAT_00ddb2a8 + iStack_181c * 4)) != '\0') &&
              (iStack_181c = iStack_181c + 1, iStack_181c < DAT_00ddb2e8));
    }
    if ((DAT_00ddb2e8 == 0) || (iStack_181c == DAT_00ddb2e8)) {
      iVar11 = 0;
      while (uVar5 != 0) {
        uVar5 = param_1[iVar11];
        if ((uVar5 & 0xfc00) == 0xd800) {
          iVar11 = iVar11 + 2;
        }
        else {
          if ((uVar5 == 0x3a) ||
             ((((uVar5 < 0x61 || (0x7a < uVar5)) && ((uVar5 < 0x41 || (0x5a < uVar5)))) &&
              ((uVar5 < 0x30 || (0x39 < uVar5)))))) break;
          iVar11 = iVar11 + 1;
        }
        uVar5 = param_1[iVar11];
      }
      if (param_1[iVar11] != 0x3a) goto LAB_0052d763;
      FUN_0056d420(param_2,param_1,iVar11 * 2 + 2);
      param_2[iVar11 + 1] = 0;
      iVar7 = iVar11 + 1;
      if ((param_1[iVar11 + 1] == 0x5c) ||
         (puStack_1820 = (ushort *)iVar7, param_1[iVar11 + 1] == 0x2f)) {
        puStack_1820 = (ushort *)(iVar11 + 2);
        goto LAB_0052d757;
      }
    }
    else {
      FUN_0056d420(param_2,param_1,iVar7 * 2);
      param_2[iVar7] = 0;
      puStack_1820 = (ushort *)iVar7;
LAB_0052d757:
    }
    bVar3 = true;
    iVar10 = iVar7;
  }
LAB_0052d763:
  if (DAT_0085e580 == 1) {
    if (bVar3) goto LAB_0052d885;
    if ((*param_1 == 0x5c) || (*param_1 == 0x2f)) {
      *param_2 = *param_4;
      puStack_1820 = (ushort *)((int)puStack_1820 + 1);
      param_2[1] = param_4[1];
      param_2[2] = 0;
      iVar10 = 2;
      local_1804 = 1;
      goto LAB_0052d885;
    }
  }
  else if (bVar3) goto LAB_0052d885;
  FUN_0056cf70(param_2,param_3,param_4);
  iVar10 = 0;
  sVar2 = *param_2;
  while (sVar2 != 0) {
    iVar10 = iVar10 + 1;
    sVar2 = param_2[iVar10];
  }
  if (DAT_00aba250 == 0) {
    FUN_0057a980();
  }
  iVar7 = FUN_00576dc0(param_4,DAT_00aba250);
  if (iVar7 != 0) {
    if (DAT_00aba250 == 0) {
      FUN_0057a980();
    }
    puVar6 = (undefined2 *)FUN_00576e20(param_4,DAT_00aba250,iVar7 + -1);
    if (DAT_00aba250 == 0) {
      FUN_0057a980();
    }
    iVar7 = FUN_00572fc0(puVar6,DAT_00aba250,&uStack_1810);
    if ((iVar7 == 0x5c) || (iVar7 == 0x2f)) {
      *puVar6 = 0;
      iVar10 = iVar10 + -1;
    }
  }
LAB_0052d885:
  puStack_1820 = param_1 + (int)puStack_1820;
  uVar5 = *puStack_1820;
  if (uVar5 != 0) {
    do {
      if ((uVar5 == 0x2f) || (uVar5 == 0x5c)) {
        if (iStack_1814 == 0) {
          puStack_1820 = puStack_1820 + 1;
        }
        else {
          iVar7 = FUN_0056d130(auStack_1800,&DAT_007d5a74);
          if (iVar7 != 0) {
            iVar7 = FUN_0056d130(auStack_1800,&DAT_007d5a6c);
            if (iVar7 == 0) {
              param_2[iVar10] = 0;
              if (DAT_00aba250 == 0) {
                FUN_0057a980();
              }
              iVar7 = FUN_00576dc0(param_2,DAT_00aba250);
              if (DAT_00aba250 == 0) {
                FUN_0057a980();
              }
              iVar7 = iVar7 + -1;
              uVar8 = FUN_00576e20(param_2,DAT_00aba250,iVar7);
              if (DAT_00aba250 == 0) {
                FUN_0057a980();
              }
              FUN_00572fc0(uVar8,DAT_00aba250,&uStack_1810);
              iVar10 = iVar10 - (uStack_1810 >> 1);
              if (param_2[iVar10] != 0x5c) {
                do {
                  if ((param_2[iVar10] == 0x2f) || (param_2[iVar10] == 0x3a)) break;
                  param_2[iVar10] = 0;
                  iVar7 = iVar7 + -1;
                  if (DAT_00aba250 == 0) {
                    FUN_0057a980();
                  }
                  uVar8 = FUN_00576e20(param_2,DAT_00aba250,iVar7);
                  if (DAT_00aba250 == 0) {
                    FUN_0057a980();
                  }
                  FUN_00572fc0(uVar8,DAT_00aba250,&uStack_1810);
                  iVar10 = iVar10 - (uStack_1810 >> 1);
                } while (param_2[iVar10] != 0x5c);
              }
              if (param_2[iVar10] == 0x3a) {
                iVar10 = iVar10 + 1;
              }
              else {
                param_2[iVar10] = 0;
              }
            }
            else {
              if (((local_1804 == 0) && ((*param_1 == 0x5c || (*param_1 == 0x2f)))) || (iVar10 != 0)
                 ) {
                param_2[iVar10] = 0x5c;
                iVar10 = iVar10 + 1;
              }
              FUN_0056cf70(param_2 + iVar10,param_3 + iVar10 * -2,auStack_1800);
              iVar10 = FUN_0050e220(param_2);
            }
          }
          puStack_1820 = puStack_1820 + 1;
          iStack_1814 = 0;
        }
      }
      else {
        uVar5 = *puStack_1820;
        auStack_1800[iStack_1814] = uVar5;
        if ((uVar5 & 0xfc00) == 0xd800) {
          auStack_1800[iStack_1814 + 1] = puStack_1820[1];
          auStack_1800[iStack_1814 + 2] = 0;
          iStack_1814 = iStack_1814 + 2;
          puStack_1820 = puStack_1820 + 2;
        }
        else {
          auStack_1800[iStack_1814 + 1] = 0;
          iStack_1814 = iStack_1814 + 1;
          puStack_1820 = puStack_1820 + 1;
        }
      }
      uVar5 = *puStack_1820;
    } while (uVar5 != 0);
    if (iStack_1814 != 0) {
      if (iVar10 != 0) {
        param_2[iVar10] = 0x5c;
        iVar10 = iVar10 + 1;
      }
      FUN_0056cf70(param_2 + iVar10,param_3 + iVar10 * -2,auStack_1800);
      sVar2 = *param_2;
      while (sVar2 != 0) {
        param_2 = param_2 + 1;
        sVar2 = *param_2;
      }
    }
  }
  return 0;
}

