
int FUN_006596d0(int param_1,uint param_2,undefined4 *param_3)

{
  int *piVar1;
  double dVar2;
  byte bVar3;
  char cVar4;
  int iVar5;
  float *pfVar6;
  float *pfVar7;
  uint uVar8;
  double *pdVar9;
  float10 fVar10;
  double *local_20;
  float *local_1c;
  uint local_18;
  undefined4 uStack_14;
  uint local_10;
  undefined4 uStack_c;
  int local_8;
  undefined4 local_4;
  
  uVar8 = param_2;
  switch(*(undefined2 *)(param_2 + 2)) {
  case 1:
  case 3:
  case 4:
  case 5:
  case 6:
  case 8:
  case 9:
  case 10:
  case 0xb:
  case 0xc:
  case 0x10:
  case 0x11:
    break;
  default:
    return 2;
  }
  iVar5 = FUN_00655060(param_1,param_2,&param_2,4,&local_20);
  if ((iVar5 != 0) || (local_20 == (double *)0x0)) {
    *param_3 = 0;
    return iVar5;
  }
  if (*(short *)(uVar8 + 2) == 0xb) {
    if ((*(byte *)(param_1 + 0xc) & 0x80) != 0) {
      FUN_0065a6c0(local_20,param_2);
    }
    *param_3 = local_20;
    return 0;
  }
  pfVar6 = (float *)FUN_006507d0(param_2 * 4);
  local_1c = pfVar6;
  if (pfVar6 == (float *)0x0) {
    FUN_006507e0(local_20);
    return 7;
  }
  switch(*(undefined2 *)(uVar8 + 2)) {
  case 1:
    uVar8 = 0;
    pfVar7 = pfVar6;
    pdVar9 = local_20;
    if (param_2 != 0) {
      do {
        bVar3 = *(byte *)pdVar9;
        pdVar9 = (double *)((int)pdVar9 + 1);
        uVar8 = uVar8 + 1;
        *pfVar7 = (float)bVar3;
        pfVar7 = pfVar7 + 1;
      } while (uVar8 < param_2);
    }
  default:
    goto switchD_0065977d_caseD_2;
  case 3:
    uVar8 = 0;
    pdVar9 = local_20;
    if (param_2 != 0) {
      do {
        if ((*(byte *)(param_1 + 0xc) & 0x80) != 0) {
          FUN_0065a5f0(pdVar9);
        }
        local_18 = (uint)*(ushort *)pdVar9;
        pdVar9 = (double *)((int)pdVar9 + 2);
        uVar8 = uVar8 + 1;
        *pfVar6 = (float)local_18;
        pfVar6 = pfVar6 + 1;
      } while (uVar8 < param_2);
    }
    break;
  case 4:
    uVar8 = 0;
    pdVar9 = local_20;
    if (param_2 != 0) {
      do {
        if ((*(byte *)(param_1 + 0xc) & 0x80) != 0) {
          FUN_0065a600(pdVar9);
        }
        local_18 = *(uint *)pdVar9;
        uStack_14 = 0;
        pdVar9 = (double *)((int)pdVar9 + 4);
        uVar8 = uVar8 + 1;
        *pfVar6 = (float)local_18;
        pfVar6 = pfVar6 + 1;
      } while (uVar8 < param_2);
    }
    break;
  case 5:
    local_18 = 0;
    pdVar9 = local_20;
    if (param_2 == 0) goto switchD_0065977d_caseD_2;
    do {
      if ((*(byte *)(param_1 + 0xc) & 0x80) != 0) {
        FUN_0065a600(pdVar9);
      }
      uVar8 = *(uint *)pdVar9;
      if ((*(byte *)(param_1 + 0xc) & 0x80) != 0) {
        FUN_0065a600((int *)((int)pdVar9 + 4));
      }
      iVar5 = *(int *)((int)pdVar9 + 4);
      pdVar9 = pdVar9 + 1;
      if (iVar5 == 0) {
        *pfVar6 = 0.0;
      }
      else {
        uStack_c = 0;
        local_4 = 0;
        *pfVar6 = (float)uVar8 / (float)iVar5;
        local_10 = uVar8;
        local_8 = iVar5;
      }
      pfVar6 = pfVar6 + 1;
      local_18 = local_18 + 1;
    } while (local_18 < param_2);
    break;
  case 6:
    uVar8 = 0;
    pfVar7 = pfVar6;
    pdVar9 = local_20;
    if (param_2 != 0) {
      do {
        cVar4 = *(char *)pdVar9;
        pdVar9 = (double *)((int)pdVar9 + 1);
        uVar8 = uVar8 + 1;
        *pfVar7 = (float)(int)cVar4;
        pfVar7 = pfVar7 + 1;
      } while (uVar8 < param_2);
    }
    goto switchD_0065977d_caseD_2;
  case 8:
    uVar8 = 0;
    pdVar9 = local_20;
    if (param_2 != 0) {
      do {
        if ((*(byte *)(param_1 + 0xc) & 0x80) != 0) {
          FUN_0065a5f0(pdVar9);
        }
        local_18 = (uint)*(short *)pdVar9;
        pdVar9 = (double *)((int)pdVar9 + 2);
        uVar8 = uVar8 + 1;
        *pfVar6 = (float)(int)local_18;
        pfVar6 = pfVar6 + 1;
      } while (uVar8 < param_2);
    }
    break;
  case 9:
    uVar8 = 0;
    pdVar9 = local_20;
    if (param_2 != 0) {
      do {
        if ((*(byte *)(param_1 + 0xc) & 0x80) != 0) {
          FUN_0065a600(pdVar9);
        }
        iVar5 = *(int *)pdVar9;
        pdVar9 = (double *)((int)pdVar9 + 4);
        uVar8 = uVar8 + 1;
        *pfVar6 = (float)iVar5;
        pfVar6 = pfVar6 + 1;
      } while (uVar8 < param_2);
    }
    break;
  case 10:
    local_18 = 0;
    pdVar9 = local_20;
    pfVar7 = pfVar6;
    if (param_2 != 0) {
      do {
        if ((*(byte *)(param_1 + 0xc) & 0x80) != 0) {
          FUN_0065a600(pdVar9);
        }
        local_1c = *(float **)pdVar9;
        if ((*(byte *)(param_1 + 0xc) & 0x80) != 0) {
          FUN_0065a600((int *)((int)pdVar9 + 4));
        }
        iVar5 = *(int *)((int)pdVar9 + 4);
        pdVar9 = pdVar9 + 1;
        if (iVar5 == 0) {
          *pfVar7 = 0.0;
        }
        else {
          local_4 = 0;
          *pfVar7 = (float)(int)local_1c / (float)iVar5;
          local_8 = iVar5;
        }
        pfVar7 = pfVar7 + 1;
        local_18 = local_18 + 1;
      } while (local_18 < param_2);
    }
    goto switchD_0065977d_caseD_2;
  case 0xc:
    if ((*(byte *)(param_1 + 0xc) & 0x80) != 0) {
      FUN_0065a700(local_20,param_2);
    }
    uVar8 = 0;
    pfVar7 = pfVar6;
    pdVar9 = local_20;
    if (param_2 != 0) {
      do {
        dVar2 = *pdVar9;
        pdVar9 = pdVar9 + 1;
        *pfVar7 = (float)dVar2;
        pfVar7 = pfVar7 + 1;
        uVar8 = uVar8 + 1;
      } while (uVar8 < param_2);
    }
    goto switchD_0065977d_caseD_2;
  case 0x10:
    uVar8 = 0;
    pdVar9 = local_20;
    if (param_2 != 0) {
      do {
        if ((*(byte *)(param_1 + 0xc) & 0x80) != 0) {
          FUN_0065a620(pdVar9);
        }
        piVar1 = (int *)((int)pdVar9 + 4);
        iVar5 = *(int *)pdVar9;
        pdVar9 = pdVar9 + 1;
        fVar10 = (float10)FUN_006512a0(iVar5,*piVar1);
        *pfVar6 = (float)fVar10;
        pfVar6 = pfVar6 + 1;
        uVar8 = uVar8 + 1;
      } while (uVar8 < param_2);
    }
    break;
  case 0x11:
    uVar8 = 0;
    pdVar9 = local_20;
    if (param_2 != 0) {
      do {
        if ((*(byte *)(param_1 + 0xc) & 0x80) != 0) {
          FUN_0065a620(pdVar9);
        }
        dVar2 = *pdVar9;
        pdVar9 = pdVar9 + 1;
        uVar8 = uVar8 + 1;
        *pfVar6 = (float)(longlong)dVar2;
        pfVar6 = pfVar6 + 1;
      } while (uVar8 < param_2);
    }
  }
  pfVar6 = local_1c;
switchD_0065977d_caseD_2:
  FUN_006507e0(local_20);
  *param_3 = pfVar6;
  return 0;
}

