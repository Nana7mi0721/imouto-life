
undefined4 FUN_006c16b0(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  if ((param_2 == *(int *)(param_1 + 0x30)) && (param_3 == *(int *)(param_1 + 0x34))) {
    return 0;
  }
  if (*(code **)(param_1 + 4) != (code *)0x0) {
    iVar1 = (**(code **)(param_1 + 4))(*(undefined4 *)(param_1 + 0x10),param_2,param_3,0);
    if (iVar1 == 0) {
      *(int *)(param_1 + 0x30) = param_2;
      *(int *)(param_1 + 0x34) = param_3;
      FUN_006a8cd0(param_1 + 0x40);
      return 0;
    }
  }
  return 0xffffff80;
}

