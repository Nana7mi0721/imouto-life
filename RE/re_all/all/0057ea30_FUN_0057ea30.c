
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0057ea30(int param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  ushort uVar4;
  int iVar5;
  float10 fVar6;
  float local_50;
  float local_4c;
  float local_40 [16];
  
  uVar4 = 8;
  if (*(ushort *)(param_1 + 0x32) < 9) {
    uVar4 = *(ushort *)(param_1 + 0x32);
  }
  if (DAT_00aa4fa0 != 0) {
    iVar5 = 0;
    piVar2 = (int *)(param_1 + 8);
    do {
      fVar6 = (float10)FUN_0056d500(_DAT_007d52d8,
                                    ((float)*piVar2 / (float)_DAT_00829840) / (float)_DAT_007d8c00);
      local_40[iVar5] = (float)fVar6;
      iVar5 = iVar5 + 1;
      piVar2 = piVar2 + 1;
    } while (iVar5 < 8);
    if (uVar4 < 3) {
      if (uVar4 == 1) {
        local_40[1] = local_40[0];
      }
      iVar5 = *(int *)(param_1 + 4);
      if (iVar5 < 0) {
        fVar6 = (float10)FUN_0056d500(_DAT_007d52d8,
                                      ((float)iVar5 / (float)_DAT_00829840) / (float)_DAT_007d8c00);
        local_40[1] = (float)fVar6 * local_40[1];
      }
      else if (0 < iVar5) {
        fVar6 = (float10)FUN_0056d500(_DAT_007d52d8,
                                      ((float)-iVar5 / (float)_DAT_00829840) / (float)_DAT_007d8c00)
        ;
        local_40[0] = (float)fVar6 * local_40[0];
      }
    }
    (**(code **)(**(int **)(param_1 + 200) + 0x38))
              (*(int **)(param_1 + 200),*(undefined4 *)(param_1 + 0x110),local_40,0);
    return 0;
  }
  if (2 < uVar4) {
    iVar5 = *(int *)(param_1 + 8);
    if (iVar5 < 1) {
      if (iVar5 < -10000) {
        iVar5 = -10000;
      }
    }
    else {
      iVar5 = 0;
    }
    (**(code **)(**(int **)(param_1 + 200) + 0x3c))(*(int **)(param_1 + 200),iVar5);
    (**(code **)(**(int **)(param_1 + 200) + 0x40))
              (*(int **)(param_1 + 200),*(undefined4 *)(param_1 + 4));
    return 0;
  }
  if (*(int *)(param_1 + 0x70) == 0) {
    iVar5 = *(int *)(param_1 + 8);
  }
  else {
    fVar6 = (float10)FUN_0057cfa0((float)*(int *)(param_1 + 8) / (float)_DAT_00829840);
    local_50 = (float)fVar6;
    fVar6 = (float10)FUN_0057cfa0((float)*(int *)(param_1 + 0xc) / (float)_DAT_00829840);
    local_4c = (float)fVar6;
    if (0.0 <= *(float *)(param_1 + 0xc4)) {
      if (0.0 < *(float *)(param_1 + 0xc4)) {
        local_4c = (1.0 - *(float *)(param_1 + 0xc4)) * local_4c;
      }
    }
    else {
      local_50 = (*(float *)(param_1 + 0xc4) + (float)_DAT_00802e18) * local_50;
    }
    fVar6 = (float10)FUN_0057cfd0(*(float *)(param_1 + 0xc0) * local_50);
    iVar5 = (int)ROUND((double)(fVar6 * (float10)_DAT_00829840));
    FUN_0057cfd0(*(float *)(param_1 + 0xc0) * local_4c);
  }
  iVar3 = *(int *)(param_1 + 4);
  iVar1 = 10000;
  if (iVar3 < 0) {
    iVar3 = iVar3 + 10000;
  }
  else {
    iVar1 = 10000 - iVar3;
    iVar3 = 10000;
  }
  if (iVar5 < 1) {
    if (iVar5 < -10000) {
      iVar5 = -10000;
    }
  }
  else {
    iVar5 = 0;
  }
  iVar1 = ((iVar5 + 10000) * iVar1) / 10000;
  iVar5 = ((iVar5 + 10000) * iVar3) / 10000;
  if (iVar5 < iVar1) {
    iVar3 = iVar1 + -10000;
    iVar5 = (int)ROUND(((float)_DAT_007d5918 / (float)iVar1) * (float)iVar5) + -10000;
  }
  else if (iVar1 < iVar5) {
    iVar3 = iVar5 + -10000;
    iVar5 = FUN_0050e270(((float)_DAT_007d5918 / (float)iVar5) * (float)iVar1);
    iVar5 = 10000 - iVar5;
  }
  else {
    iVar3 = iVar1 + -10000;
    iVar5 = 0;
  }
  (**(code **)(**(int **)(param_1 + 200) + 0x40))(*(int **)(param_1 + 200),iVar5);
  (**(code **)(**(int **)(param_1 + 200) + 0x3c))(*(int **)(param_1 + 200),iVar3);
  return 0;
}

