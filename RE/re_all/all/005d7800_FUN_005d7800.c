
undefined4 FUN_005d7800(int param_1)

{
  int iVar1;
  int iVar2;
  
  FUN_0056da60(param_1 + 0x74,"..\\..\\..\\..\\Source\\Library\\Main\\DxHeap.cpp",0x9bc);
  for (iVar1 = *(int *)(param_1 + 0x6c); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x3c)) {
    iVar2 = iVar1;
    if (*(int *)(param_1 + 0x2c) == 0) {
      iVar2 = *(int *)(iVar1 + 0x28);
    }
    FUN_005d7680(iVar2,*(int *)(param_1 + 0x2c));
  }
  FUN_0056dac0(param_1 + 0x74);
  return 0;
}

