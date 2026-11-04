
int FUN_006551f0(int param_1,int param_2,undefined4 *param_3)

{
  float *pfVar1;
  longlong lVar2;
  float fVar3;
  int iVar4;
  double *pdVar5;
  double *pdVar6;
  double *pdVar7;
  float *pfVar8;
  float10 fVar9;
  double *local_2c;
  float *local_28;
  double *local_24;
  float local_20;
  undefined4 uStack_1c;
  float local_18;
  undefined4 uStack_14;
  float local_10;
  undefined4 uStack_c;
  
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
  iVar4 = FUN_00655060(param_1,param_2,&local_2c,8,&local_28);
  if ((iVar4 != 0) || (local_28 == (float *)0x0)) {
    *param_3 = 0;
    return iVar4;
  }
  if (*(short *)(param_2 + 2) == 0xc) {
    if ((*(byte *)(param_1 + 0xc) & 0x80) != 0) {
      FUN_0065a700(local_28,local_2c);
    }
    *param_3 = local_28;
    return 0;
  }
  pdVar5 = (double *)FUN_006507d0((int)local_2c * 8);
  local_24 = pdVar5;
  if (pdVar5 == (double *)0x0) {
    FUN_006507e0(local_28);
    return 7;
  }
  switch(*(undefined2 *)(param_2 + 2)) {
  case 1:
    pdVar6 = (double *)0x0;
    pdVar7 = pdVar5;
    pfVar8 = local_28;
    if (local_2c != (double *)0x0) {
      do {
        local_24 = (double *)(uint)*(byte *)pfVar8;
        pfVar8 = (float *)((int)pfVar8 + 1);
        pdVar6 = (double *)((int)pdVar6 + 1);
        *pdVar7 = (double)(int)local_24;
        pdVar7 = pdVar7 + 1;
      } while (pdVar6 < local_2c);
    }
  default:
    goto switchD_0065529d_caseD_2;
  case 3:
    pdVar7 = (double *)0x0;
    pfVar8 = local_28;
    if (local_2c != (double *)0x0) {
      do {
        if ((*(byte *)(param_1 + 0xc) & 0x80) != 0) {
          FUN_0065a5f0(pfVar8);
        }
        local_20 = (float)(uint)*(ushort *)pfVar8;
        pfVar8 = (float *)((int)pfVar8 + 2);
        pdVar7 = (double *)((int)pdVar7 + 1);
        *pdVar5 = (double)(int)local_20;
        pdVar5 = pdVar5 + 1;
      } while (pdVar7 < local_2c);
    }
    break;
  case 4:
    pdVar7 = (double *)0x0;
    pfVar8 = local_28;
    if (local_2c != (double *)0x0) {
      do {
        if ((*(byte *)(param_1 + 0xc) & 0x80) != 0) {
          FUN_0065a600(pfVar8);
        }
        local_20 = *pfVar8;
        uStack_1c = 0;
        pfVar8 = pfVar8 + 1;
        pdVar7 = (double *)((int)pdVar7 + 1);
        *pdVar5 = (double)(uint)local_20;
        pdVar5 = pdVar5 + 1;
      } while (pdVar7 < local_2c);
    }
    break;
  case 5:
    local_24 = (double *)0x0;
    pfVar8 = local_28;
    pdVar7 = pdVar5;
    if (local_2c != (double *)0x0) {
      do {
        if ((*(byte *)(param_1 + 0xc) & 0x80) != 0) {
          FUN_0065a600(pfVar8);
        }
        local_20 = *pfVar8;
        if ((*(byte *)(param_1 + 0xc) & 0x80) != 0) {
          FUN_0065a600(pfVar8 + 1);
        }
        fVar3 = pfVar8[1];
        pfVar8 = pfVar8 + 2;
        if (fVar3 == 0.0) {
          *(undefined4 *)pdVar7 = 0;
          *(undefined4 *)((int)pdVar7 + 4) = 0;
        }
        else {
          uStack_14 = 0;
          local_18 = local_20;
          uStack_c = 0;
          *pdVar7 = (double)(uint)local_20 / (double)(uint)fVar3;
          local_10 = fVar3;
        }
        pdVar7 = pdVar7 + 1;
        local_24 = (double *)((int)local_24 + 1);
      } while (local_24 < local_2c);
    }
    goto switchD_0065529d_caseD_2;
  case 6:
    pdVar6 = (double *)0x0;
    pdVar7 = pdVar5;
    pfVar8 = local_28;
    if (local_2c != (double *)0x0) {
      do {
        local_24 = (double *)(int)*(char *)pfVar8;
        pfVar8 = (float *)((int)pfVar8 + 1);
        pdVar6 = (double *)((int)pdVar6 + 1);
        *pdVar7 = (double)(int)local_24;
        pdVar7 = pdVar7 + 1;
      } while (pdVar6 < local_2c);
    }
    goto switchD_0065529d_caseD_2;
  case 8:
    pdVar7 = (double *)0x0;
    pfVar8 = local_28;
    if (local_2c != (double *)0x0) {
      do {
        if ((*(byte *)(param_1 + 0xc) & 0x80) != 0) {
          FUN_0065a5f0(pfVar8);
        }
        local_20 = (float)(int)*(short *)pfVar8;
        pfVar8 = (float *)((int)pfVar8 + 2);
        pdVar7 = (double *)((int)pdVar7 + 1);
        *pdVar5 = (double)(int)local_20;
        pdVar5 = pdVar5 + 1;
      } while (pdVar7 < local_2c);
    }
    break;
  case 9:
    pdVar7 = (double *)0x0;
    pfVar8 = local_28;
    if (local_2c != (double *)0x0) {
      do {
        if ((*(byte *)(param_1 + 0xc) & 0x80) != 0) {
          FUN_0065a600(pfVar8);
        }
        fVar3 = *pfVar8;
        pfVar8 = pfVar8 + 1;
        pdVar7 = (double *)((int)pdVar7 + 1);
        *pdVar5 = (double)(int)fVar3;
        pdVar5 = pdVar5 + 1;
      } while (pdVar7 < local_2c);
    }
    break;
  case 10:
    local_24 = (double *)0x0;
    pfVar8 = local_28;
    pdVar7 = pdVar5;
    if (local_2c != (double *)0x0) {
      do {
        if ((*(byte *)(param_1 + 0xc) & 0x80) != 0) {
          FUN_0065a600(pfVar8);
        }
        local_20 = *pfVar8;
        if ((*(byte *)(param_1 + 0xc) & 0x80) != 0) {
          FUN_0065a600(pfVar8 + 1);
        }
        fVar3 = pfVar8[1];
        pfVar8 = pfVar8 + 2;
        if (fVar3 == 0.0) {
          *(undefined4 *)pdVar7 = 0;
          *(undefined4 *)((int)pdVar7 + 4) = 0;
        }
        else {
          uStack_c = 0;
          *pdVar7 = (double)(int)local_20 / (double)(uint)fVar3;
          local_10 = fVar3;
        }
        pdVar7 = pdVar7 + 1;
        local_24 = (double *)((int)local_24 + 1);
      } while (local_24 < local_2c);
    }
    goto switchD_0065529d_caseD_2;
  case 0xb:
    if ((*(byte *)(param_1 + 0xc) & 0x80) != 0) {
      FUN_0065a6c0(local_28,local_2c);
    }
    pdVar6 = (double *)0x0;
    pdVar7 = pdVar5;
    pfVar8 = local_28;
    if (local_2c != (double *)0x0) {
      do {
        fVar3 = *pfVar8;
        pfVar8 = pfVar8 + 1;
        *pdVar7 = (double)fVar3;
        pdVar7 = pdVar7 + 1;
        pdVar6 = (double *)((int)pdVar6 + 1);
      } while (pdVar6 < local_2c);
    }
    goto switchD_0065529d_caseD_2;
  case 0x10:
    pdVar7 = (double *)0x0;
    pfVar8 = local_28;
    if (local_2c != (double *)0x0) {
      do {
        if ((*(byte *)(param_1 + 0xc) & 0x80) != 0) {
          FUN_0065a620(pfVar8);
        }
        pfVar1 = pfVar8 + 1;
        fVar3 = *pfVar8;
        pfVar8 = pfVar8 + 2;
        fVar9 = (float10)FUN_006512c0(fVar3,*pfVar1);
        *pdVar5 = (double)fVar9;
        pdVar5 = pdVar5 + 1;
        pdVar7 = (double *)((int)pdVar7 + 1);
      } while (pdVar7 < local_2c);
    }
    break;
  case 0x11:
    pdVar7 = (double *)0x0;
    pfVar8 = local_28;
    if (local_2c != (double *)0x0) {
      do {
        if ((*(byte *)(param_1 + 0xc) & 0x80) != 0) {
          FUN_0065a620(pfVar8);
        }
        lVar2 = *(longlong *)pfVar8;
        pfVar8 = pfVar8 + 2;
        pdVar7 = (double *)((int)pdVar7 + 1);
        *pdVar5 = (double)lVar2;
        pdVar5 = pdVar5 + 1;
      } while (pdVar7 < local_2c);
    }
  }
  pdVar5 = local_24;
switchD_0065529d_caseD_2:
  FUN_006507e0(local_28);
  *param_3 = pdVar5;
  return 0;
}

