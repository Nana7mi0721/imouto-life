
undefined4 FUN_0065c870(int param_1,int *param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  ushort uVar4;
  
  if (param_3 == 0) {
    *param_2 = *param_2 + 1;
    return 1;
  }
  uVar4 = *(short *)(param_1 + 0x62) - *(short *)(param_1 + 0x9c);
  iVar3 = 1 << (*(byte *)(param_1 + 0x54) & 0x1f);
  if (uVar4 < 4) {
    if (uVar4 == 3) goto LAB_0065c8bb;
    if (uVar4 == 2) goto LAB_0065c8e6;
    if (uVar4 != 0) goto LAB_0065c910;
  }
  else {
    uVar4 = 3;
LAB_0065c8bb:
    iVar1 = FUN_00650860(*(undefined4 *)(param_1 + 200),*(undefined4 *)(param_1 + 0xd0),iVar3 * 2);
    if (iVar1 != 0) goto LAB_0065c910;
    uVar4 = 2;
LAB_0065c8e6:
    iVar1 = FUN_00650860(*(undefined4 *)(param_1 + 200),*(undefined4 *)(param_1 + 0xcc),iVar3 * 2);
    if (iVar1 != 0) goto LAB_0065c910;
  }
  uVar4 = 1;
LAB_0065c910:
  iVar1 = FUN_006507d0((uint)uVar4 * iVar3 * 2);
  if (iVar1 == 0) {
    FUN_006512e0(*(undefined4 *)(param_1 + 0x274),"TIFFWriteDirectoryTagTransferfunction",
                 s_Out_of_memory_00a066e4);
    return 0;
  }
  FUN_00650840(iVar1,*(undefined4 *)(param_1 + 200),iVar3 * 2);
  if (1 < uVar4) {
    FUN_00650840(iVar3 * 2 + iVar1,*(undefined4 *)(param_1 + 0xcc),iVar3 * 2);
  }
  if (2 < uVar4) {
    FUN_00650840(iVar1 + iVar3 * 4,*(undefined4 *)(param_1 + 0xd0),iVar3 * 2);
  }
  uVar2 = FUN_0065cc60(param_1,param_2,param_3,0x12d,(uint)uVar4 * iVar3,iVar1);
  FUN_006507e0(iVar1);
  return uVar2;
}

