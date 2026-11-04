
undefined4 FUN_005d7260(int param_1)

{
  int iVar1;
  int iVar2;
  undefined1 local_20 [32];
  
  FUN_0056da60(param_1 + 0x74,"..\\..\\..\\..\\Source\\Library\\Main\\DxHeap.cpp",0x53d);
  iVar1 = *(int *)(param_1 + 0x50);
  while (iVar2 = iVar1, iVar2 != 0) {
    iVar1 = *(int *)(iVar2 + 0x24);
    if ((*(byte *)(iVar2 + 0x28) & 1) != 0) {
      FUN_0056d420(local_20,iVar2 + 0x2c,0x20);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_1 + 8),local_20);
    }
  }
  FUN_0056dac0(param_1 + 0x74);
  FUN_0056d380(param_1,0,0x2320);
  return 0;
}

