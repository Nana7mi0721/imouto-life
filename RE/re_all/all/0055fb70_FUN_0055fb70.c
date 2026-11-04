
undefined4
FUN_0055fb70(int param_1,int param_2,undefined1 param_3,uint param_4,int param_5,undefined4 *param_6
            ,uint param_7,int param_8)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  int *piVar7;
  undefined *puVar8;
  int *local_4a4;
  int iStack_4a0;
  undefined4 uStack_49c;
  undefined4 uStack_498;
  undefined4 uStack_494;
  undefined4 uStack_490;
  undefined4 uStack_48c;
  undefined4 uStack_488;
  undefined4 uStack_484;
  undefined1 auStack_480 [20];
  undefined1 auStack_46c [1132];
  
  iVar1 = FUN_0057e0e0();
  if (iVar1 == 0) {
    return 0xffffffff;
  }
  if (param_8 == 0) {
    if (DAT_00cc4db0 == 0) {
      return 0xffffffff;
    }
    if ((int)param_4 < 0) {
      return 0xffffffff;
    }
    if ((param_4 & 0x7c000000) != DAT_00cc4dd8) {
      return 0xffffffff;
    }
    if (DAT_00cc4de0 <= (int)(param_4 & 0xffff)) {
      return 0xffffffff;
    }
    piVar7 = *(int **)(DAT_00cc4db4 + (param_4 & 0xffff) * 4);
    if (piVar7 == (int *)0x0) {
      return 0xffffffff;
    }
    if (*piVar7 * 0x10000 != (param_4 & 0x3ff0000)) {
      return 0xffffffff;
    }
    if (piVar7[4] != 0) {
      return 0xffffffff;
    }
  }
  else {
    if (DAT_00cc4db0 == 0) {
      return 0xffffffff;
    }
    if ((int)param_4 < 0) {
      return 0xffffffff;
    }
    if ((param_4 & 0x7c000000) != DAT_00cc4dd8) {
      return 0xffffffff;
    }
    if (DAT_00cc4de0 <= (int)(param_4 & 0xffff)) {
      return 0xffffffff;
    }
    piVar7 = *(int **)(DAT_00cc4db4 + (param_4 & 0xffff) * 4);
    if (piVar7 == (int *)0x0) {
      return 0xffffffff;
    }
    if (*piVar7 * 0x10000 != (param_4 & 0x3ff0000)) {
      return 0xffffffff;
    }
  }
  iVar1 = piVar7[0x92d];
  if (0 < iVar1) {
    if (piVar7[0x482] != 1) {
      FUN_0056bb10(&DAT_007d6668);
      return 0xffffffff;
    }
    iVar1 = FUN_0055fa80(param_4,piVar7,&local_4a4,0);
    if ((iVar1 == 0) && (iVar1 = FUN_00551870(local_4a4), iVar1 != 0)) {
      FUN_0056bb10(&DAT_007d6620);
      return 0xffffffff;
    }
    iVar1 = piVar7[0x92d];
    if (iVar1 == 3) {
      FUN_0056bb10(&DAT_007d65e4);
      return 0xffffffff;
    }
  }
  piVar6 = piVar7 + iVar1 * 0x128 + 0x48c;
  FUN_0056d380(piVar6,0,0x4a0);
  piVar6[1] = param_5;
  piVar6[0xc] = -1;
  (**(code **)(param_2 + 4))(*(undefined4 *)(param_2 + 0x18),0,0,0);
  if (param_5 == 0) {
    iVar1 = FUN_0055bb40(param_2,&iStack_4a0,&local_4a4);
    if (iVar1 < 0) {
LAB_0055fe3d:
      puVar8 = &DAT_007d659c;
      goto LAB_0055fdbb;
    }
    uStack_484 = FUN_0052d000(iStack_4a0,local_4a4);
    puVar3 = (undefined4 *)FUN_0052c7a0();
    uStack_49c = *puVar3;
    uStack_498 = puVar3[1];
    uStack_494 = puVar3[2];
    uStack_490 = puVar3[3];
    uStack_48c = puVar3[4];
    uStack_488 = puVar3[5];
    FUN_00597260(auStack_46c,&uStack_49c,*(undefined4 *)(param_1 + 0x30),
                 *(undefined4 *)(param_1 + 0x34),*(undefined4 *)(param_1 + 0x38));
    local_4a4 = (int *)FUN_005971c0(auStack_46c,auStack_480,piVar6 + 2,piVar6 + 3);
    FUN_00597060(auStack_46c);
    FUN_0052d050(uStack_484);
    FUN_0056e1d0(iStack_4a0);
    if ((int)local_4a4 < 0) {
      puVar8 = &DAT_007d657c;
      goto LAB_0055fdbb;
    }
    iVar1 = FUN_0055b9b0(&iStack_4a0,&local_4a4,auStack_480,0x12,piVar6[2],piVar6[3]);
    if (iVar1 < 0) {
      return 0xffffffff;
    }
    iVar1 = FUN_0052d000(iStack_4a0,local_4a4);
    piVar6[10] = iVar1;
    piVar2 = (int *)FUN_0052c7a0();
    piVar6[4] = *piVar2;
    piVar6[5] = piVar2[1];
    piVar6[6] = piVar2[2];
    piVar6[7] = piVar2[3];
    piVar6[8] = piVar2[4];
    piVar6[9] = piVar2[5];
    FUN_00597260(piVar6 + 0xd,piVar6 + 4,*(undefined4 *)(param_1 + 0x30),
                 *(undefined4 *)(param_1 + 0x34),*(undefined4 *)(param_1 + 0x38));
    FUN_0056e1d0(piVar6[2]);
    piVar6[2] = iStack_4a0;
    piVar6[3] = (int)local_4a4;
    *param_6 = 1;
  }
  else if (param_5 == 2) {
    iVar1 = FUN_0055bb40(param_2,piVar6 + 2,piVar6 + 3);
    if (iVar1 < 0) goto LAB_0055fe3d;
    local_4a4 = piVar6 + 2;
    iVar1 = FUN_0052d000(*local_4a4,piVar6[3]);
    piVar6[10] = iVar1;
    piVar2 = (int *)FUN_0052c7a0();
    piVar6[4] = *piVar2;
    piVar6[5] = piVar2[1];
    piVar6[6] = piVar2[2];
    piVar6[7] = piVar2[3];
    piVar6[8] = piVar2[4];
    piVar6[9] = piVar2[5];
    iVar1 = FUN_00597260(piVar6 + 0xd,piVar6 + 4,*(undefined4 *)(param_1 + 0x30),
                         *(undefined4 *)(param_1 + 0x34),*(undefined4 *)(param_1 + 0x38));
    if (iVar1 < 0) {
      FUN_0052d050(piVar6[10]);
      piVar7 = local_4a4;
      FUN_0056e1d0(*local_4a4);
      *piVar7 = 0;
      FUN_0056bca0(&DAT_007d65c0);
      return 0xffffffff;
    }
    if ((((*(int *)(param_1 + 0x1c) == *(int *)(param_1 + 0x24)) &&
         (*(int *)(param_1 + 0x20) == *(int *)(param_1 + 0x28))) && (*(int *)(param_1 + 0x2c) == 0))
       && (iVar1 = FUN_00597100(piVar6 + 0xd,&local_4a4,&iStack_4a0), -1 < iVar1)) {
      *(int **)(param_1 + 0x20) = local_4a4;
      *(int *)(param_1 + 0x28) = iStack_4a0;
    }
    *param_6 = 1;
  }
  else if (param_5 == 3) {
    piVar7[0x931] = 1;
    piVar6[2] = 0;
    piVar6[3] = 0;
    piVar6[10] = 0;
    iVar1 = FUN_00597260(piVar6 + 0xd,param_2,*(undefined4 *)(param_1 + 0x30),
                         *(undefined4 *)(param_1 + 0x34),*(undefined4 *)(param_1 + 0x38));
    if (iVar1 < 0) {
      puVar8 = &DAT_007d65c0;
      goto LAB_0055fdbb;
    }
    if (((*(int *)(param_1 + 0x1c) == *(int *)(param_1 + 0x24)) &&
        (*(int *)(param_1 + 0x20) == *(int *)(param_1 + 0x28))) &&
       ((*(int *)(param_1 + 0x2c) == 0 &&
        (iVar1 = FUN_00597100(piVar6 + 0xd,&local_4a4,&iStack_4a0), -1 < iVar1)))) {
      *(int **)(param_1 + 0x20) = local_4a4;
      *(int *)(param_1 + 0x28) = iStack_4a0;
    }
    *param_6 = 0;
  }
  if (piVar7[0x92d] == 0) {
    FUN_00596880(piVar6 + 0xd,piVar7 + 0x47d);
    if (((param_7 == 0xffffffff) || (DAT_00cc4db0 == 0)) ||
       (((((int)param_7 < 0 ||
          ((((param_7 & 0x7c000000) != DAT_00cc4dd8 || (DAT_00cc4de0 <= (int)(param_7 & 0xffff))) ||
           (piVar2 = *(int **)(DAT_00cc4db4 + (param_7 & 0xffff) * 4), piVar2 == (int *)0x0)))) ||
         (((*piVar2 * 0x10000 != (param_7 & 0x3ff0000) || (piVar2[4] != 0)) || (piVar2[0x482] != 1))
         )) || ((piVar2[0x484] != -1 ||
                (iVar1 = FUN_0056d3d0(piVar7 + 0x47d,piVar2 + 0x47d,0x12), iVar1 != 0)))))) {
      uVar5 = (uint)*(ushort *)(piVar7 + 0x480);
      iVar1 = (-(uint)(param_5 != 3) & 0xfffff400) + 0xd00;
      FUN_0055bda0(piVar7 + 0x47d,
                   (((((uint)(piVar7[0x47f] * iVar1) >> 8) - 1) + uVar5) / uVar5) * uVar5,1,1,
                   param_4,param_8);
      uVar5 = (uint)*(ushort *)(piVar7 + 0x480);
      piVar7[0x484] = -1;
      piVar7[0x489] = (((((uint)(piVar7[0x47f] * iVar1) >> 8) - 1) + uVar5) / uVar5) * uVar5;
      piVar7[0x96b] = piVar7[0x47e];
    }
    else {
      FUN_0056da60(&DAT_00a837b0,"..\\..\\..\\..\\Source\\Library\\Main\\DxSound.cpp",0x417);
      piVar7[0x482] = 1;
      piVar7[0x1c] = 1;
      FUN_005807e0(&DAT_00a83790,piVar7 + 0x93a,param_4,piVar7);
      FUN_0056dac0(&DAT_00a837b0);
      piVar7[0x484] = param_7;
      piVar2[0x485] = piVar2[0x485] + 1;
    }
    piVar7[0x485] = 0;
    piVar7[0x486] = -1;
    piVar7[0x487] = 0;
  }
  else {
    FUN_00596880(piVar6 + 0xd,auStack_480);
    iVar1 = FUN_0056d3d0(auStack_480,piVar7 + 0x47d,0x12);
    if (iVar1 != 0) {
      FUN_00597060(piVar6 + 0xd);
      if (piVar6[10] != 0) {
        FUN_0052d050(piVar6[10]);
        piVar6[10] = 0;
      }
      if (piVar6[2] != 0) {
        FUN_0056e1d0(piVar6[2]);
        piVar6[2] = 0;
      }
      puVar8 = &DAT_007d6540;
LAB_0055fdbb:
      FUN_0056bca0(puVar8);
      return 0xffffffff;
    }
  }
  *(undefined1 *)piVar6 = param_3;
  piVar7[0x92d] = piVar7[0x92d] + 1;
  piVar7[0x932] = 0;
  if (0 < piVar7[0x92d]) {
    piVar6 = piVar7 + 0x499;
    iVar1 = 0;
    do {
      iVar4 = FUN_00597160(piVar6);
      iVar1 = iVar1 + 1;
      piVar6 = piVar6 + 0x128;
      piVar7[0x932] = piVar7[0x932] + iVar4 / (int)(uint)*(ushort *)(piVar7 + 0x480);
    } while (iVar1 < piVar7[0x92d]);
  }
  return 0;
}

