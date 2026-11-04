
undefined4 FUN_0065c7b0(int param_1,int *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  if (param_3 == 0) {
    *param_2 = *param_2 + 1;
    return 1;
  }
  iVar4 = 1 << (*(byte *)(param_1 + 0x54) & 0x1f);
  iVar2 = FUN_006507d0(iVar4 * 6);
  if (iVar2 == 0) {
    FUN_006512e0(*(undefined4 *)(param_1 + 0x274),"TIFFWriteDirectoryTagColormap",
                 s_Out_of_memory_00a066e4);
    return 0;
  }
  iVar1 = iVar4 * 2;
  FUN_00650840(iVar2,*(undefined4 *)(param_1 + 0x8c),iVar1);
  FUN_00650840(iVar1 + iVar2,*(undefined4 *)(param_1 + 0x90),iVar1);
  FUN_00650840(iVar2 + iVar4 * 4,*(undefined4 *)(param_1 + 0x94),iVar1);
  uVar3 = FUN_0065cc60(param_1,param_2,param_3,0x140,iVar4 * 3,iVar2);
  FUN_006507e0(iVar2);
  return uVar3;
}

