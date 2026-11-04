
int * FUN_00570cc0(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  undefined1 local_c04 [4];
  undefined1 local_c00 [1536];
  undefined1 local_600 [1536];
  
  if (*(int *)(param_1 + 0x884) == 1) {
    iVar2 = FUN_0056ef10(param_1);
    while (iVar2 == 0) {
      FUN_0056da20(0);
      iVar2 = FUN_0056ef10(param_1);
    }
  }
  piVar3 = (int *)FUN_0056e030(0x60c,"..\\..\\..\\..\\Source\\Library\\Main\\DxArchive_.cpp",0x91b);
  if (piVar3 == (int *)0x0) {
    return (int *)0xffffffff;
  }
  *piVar3 = param_1;
  FUN_0056fdf0(param_2,local_600,0x600,local_c00,0x600);
  FUN_00577a40(*(undefined4 *)(param_1 + 0x38),local_c00);
  FUN_00577a40(*(undefined4 *)(param_1 + 0x38),local_600);
  iVar2 = FUN_00572fc0(local_c00,*(undefined4 *)(param_1 + 0x38),local_c04);
  if (iVar2 == 0) {
    piVar3[0x181] = *(int *)(param_1 + 0x54);
  }
  else {
    uVar1 = *(undefined4 *)(param_1 + 0x54);
    iVar2 = FUN_0056fab0(param_1,local_c00,0,0);
    if (iVar2 == -1) {
      FUN_0056e1d0(piVar3);
      *(undefined4 *)(param_1 + 0x54) = uVar1;
      return (int *)0xffffffff;
    }
    piVar3[0x181] = *(int *)(param_1 + 0x54);
    *(undefined4 *)(param_1 + 0x54) = uVar1;
  }
  piVar3[0x182] = 0;
  FUN_00576f40(*(undefined4 *)(param_1 + 0x38),piVar3 + 1,0x600,local_600);
  iVar2 = FUN_00570800(piVar3,param_3);
  if (iVar2 == -1) {
    FUN_0056e1d0(piVar3);
    return (int *)0xffffffff;
  }
  piVar3[0x182] = piVar3[0x182] + 1;
  return piVar3;
}

