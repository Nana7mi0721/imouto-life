
undefined4 FUN_005fa270(int param_1)

{
  short sVar1;
  int iVar2;
  ushort uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined1 *local_10;
  undefined1 *local_c;
  undefined1 *local_8;
  code *local_4;
  
  iVar2 = param_1;
  *(undefined4 *)(param_1 + 0x4a) = 0;
  local_10 = &LAB_005fa350;
  local_c = &LAB_005fa380;
  local_8 = &LAB_005fa3b0;
  local_4 = FUN_0060b400;
  iVar4 = FUN_006c0eb0(param_1 + 0xc,&local_10,0,0,&param_1);
  *(int *)(iVar2 + 0x4e) = iVar4;
  if (iVar4 == 0) {
    return 0xffffffff;
  }
  *(undefined4 *)(iVar2 + 0x4a) = 1;
  iVar4 = FUN_006c2650(iVar4,0xffffffff);
  if (iVar4 == 0) {
    return 0xffffffff;
  }
  *(undefined2 *)(iVar2 + 0x48) = 0;
  *(undefined2 *)(iVar2 + 0x38) = 1;
  sVar1 = *(short *)(iVar4 + 4);
  *(undefined4 *)(iVar2 + 0x3c) = 48000;
  *(short *)(iVar2 + 0x3a) = sVar1;
  *(undefined2 *)(iVar2 + 0x46) = 0x10;
  uVar3 = sVar1 << 1;
  *(ushort *)(iVar2 + 0x44) = uVar3;
  *(uint *)(iVar2 + 0x40) = (uint)uVar3 * 48000;
  *(uint *)(iVar2 + 0x52) = (uint)uVar3;
  *(undefined4 *)(iVar2 + 0x450) = 0x1000;
  uVar5 = FUN_005fa240(iVar2);
  *(undefined4 *)(iVar2 + 0x34) = uVar5;
  *(undefined4 *)(iVar2 + 8) = 2;
  return 0;
}

