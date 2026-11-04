
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_0057ba50(int *param_1,int param_2,undefined4 param_3,undefined4 param_4,int *param_5,
                 int *param_6,undefined4 param_7,int param_8,int param_9)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  double local_54;
  int local_4c;
  int local_48;
  int local_44;
  undefined4 local_3c [2];
  undefined4 local_34;
  undefined4 local_c;
  undefined4 local_4;
  
  uVar2 = FUN_005809a0(6,param_9,0xffffffff);
  if ((int)uVar2 < 0) {
    return 0xffffffff;
  }
  if (((((DAT_00cc5680 == 0) || ((int)uVar2 < 0)) || ((uVar2 & 0x7c000000) != DAT_00cc56a8)) ||
      ((DAT_00cc56b0 <= (int)(uVar2 & 0xffff) ||
       (piVar1 = *(int **)(DAT_00cc5684 + (uVar2 & 0xffff) * 4), piVar1 == (int *)0x0)))) ||
     (*piVar1 * 0x10000 != (uVar2 & 0x3ff0000))) {
    return 0xffffffff;
  }
  piVar1[0x2f] = *param_1;
  piVar1[0x30] = param_1[1];
  piVar1[0x31] = param_1[2];
  if (param_2 == 0) {
    iVar3 = FUN_0052d000(param_3,param_4);
    piVar1[0x15] = iVar3;
    uVar4 = FUN_0052c7a0();
    piVar1[0x16] = 1;
  }
  else {
    iVar3 = thunk_FUN_00572540(param_2,0,1,0);
    piVar1[0x15] = iVar3;
    uVar4 = FUN_0052c790();
    piVar1[0x16] = 0;
  }
  iVar3 = FUN_005fa480(uVar4,piVar1[0x15],0x14,piVar1[0x31],piVar1[0x31],param_9);
  piVar1[0xe] = iVar3;
  if (iVar3 == 0) {
    piVar1[0x1b] = 0;
    if (piVar1[0x16] == 0) {
      thunk_FUN_00571d20();
    }
    else {
      FUN_0052d050();
    }
    piVar1[0x15] = 0;
  }
  if (piVar1[0xe] == 0) {
    if ((param_2 == 0) ||
       (iVar3 = FUN_005db590(piVar1,param_1,param_2,param_5,param_6,param_7,param_8,param_9),
       iVar3 == -1)) {
      FUN_0056bb10();
      if (param_9 != 0) {
        FUN_00580f70();
      }
      FUN_00580b80();
      return 0xffffffff;
    }
    piVar1[0x2d] = piVar1[0x141];
    piVar1[0x2e] = piVar1[0x142];
    piVar1[0x149] = (int)(piVar1 + 0x37);
  }
  else {
    FUN_005fc490(piVar1[0xe],&local_54);
    piVar1[0x2d] = local_48;
    piVar1[0x2e] = local_44;
    if (param_5 != (int *)0x0) {
      *param_5 = local_48;
    }
    if (param_6 != (int *)0x0) {
      *param_6 = local_44;
    }
    *(double *)(piVar1 + 0x18) = local_54;
    iVar3 = FUN_0050e240((_DAT_007d1010 / local_54) * (double)local_4c);
    piVar1[0x14] = iVar3;
    if (param_8 == 0) {
      FUN_00550fd0();
      local_3c[0] = 1;
      local_4 = 1;
      local_c = 0xfffffffd;
      if (param_2 == 0) {
        local_34 = 2;
        iVar3 = FUN_00562e30(local_3c,1,0xffffffff,param_3,param_4,1,0xffffffff,0,param_9);
      }
      else {
        local_34 = 3;
        iVar3 = FUN_005633a0(local_3c,param_2);
      }
      piVar1[0x1c] = iVar3;
      iVar3 = FUN_0055d360();
      piVar1[0x1e] = iVar3;
      iVar3 = FUN_005611b0(piVar1[0x1c]);
      piVar1[0x1d] = iVar3;
      piVar1[0x1a] = (uint)(piVar1[0x14] < piVar1[0x1e]);
    }
    else {
      piVar1[0x1c] = -1;
    }
    piVar1[0x20] = 0;
    piVar1[0x21] = 0x3ff00000;
    piVar1[0xd] = 1;
    iVar3 = FUN_005fc430();
    piVar1[0x149] = iVar3;
    piVar1[0x36] = 0;
  }
  piVar1[0x148] = 0;
  piVar1[0x33] = 1;
  piVar1[0x32] = 0;
  piVar1[0xc] = 1;
  if (param_9 != 0) {
    FUN_00580f70();
  }
  return uVar2;
}

