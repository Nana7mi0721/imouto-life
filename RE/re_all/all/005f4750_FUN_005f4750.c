
undefined4 FUN_005f4750(int param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined1 local_80 [128];
  
  if (DAT_00f3a070 == 0) {
    return 0xffffffff;
  }
  iVar2 = *(int *)(param_1 + 4);
  piVar1 = (int *)(&DAT_00dda524 + iVar2 * 4);
  if (*(int *)(&DAT_00dda524 + iVar2 * 4) < 0) {
    iVar4 = FUN_005f2360(0);
    *piVar1 = iVar4;
    if (iVar4 < 0) {
      FUN_005764b0((&PTR_s_BasBF_Normal_pso_00a05858)[iVar2],0xffffffff,0x7ffd,local_80,0x80,0x4b0);
      FUN_0056bca0(&DAT_00802650,local_80);
      return 0xffffffff;
    }
    FUN_00580830(iVar4,piVar1);
  }
  puVar3 = *(undefined4 **)(DAT_00ef1ba8 + 8);
  *puVar3 = *(undefined4 *)(param_1 + 0x18);
  puVar3[1] = *(undefined4 *)(param_1 + 0x18);
  puVar3[2] = *(undefined4 *)(param_1 + 0x18);
  puVar3[3] = *(undefined4 *)(param_1 + 0x18);
  *(undefined4 *)(DAT_00ef1ba8 + 0xc) = 1;
  FUN_005bc8e0(DAT_00ef1ba8);
  FUN_005f23c0(*piVar1,1,1,0xffffffff,0);
  return 0;
}

