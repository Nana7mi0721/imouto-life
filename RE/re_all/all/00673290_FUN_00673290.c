
void FUN_00673290(int param_1,undefined4 param_2,int param_3)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined1 local_10 [4];
  undefined1 local_c [4];
  char cStack_8;
  char cStack_7;
  undefined1 uStack_6;
  undefined1 local_5;
  undefined1 uStack_4;
  
  if ((*(byte *)(param_1 + 0x74) & 1) != 0) {
    FUN_00668a30(param_1,s_out_of_place_00a0cdb4);
  }
  if (param_3 != 0xd) {
    FUN_00668a30(param_1,s_invalid_00a0cdac);
  }
  *(uint *)(param_1 + 0x74) = *(uint *)(param_1 + 0x74) | 1;
  FUN_00673110(param_1,local_10,0xd);
  FUN_00673140(param_1,0);
  iVar2 = FUN_00672f80(param_1,local_10);
  uVar3 = FUN_00672f80(param_1,local_c);
  *(undefined1 *)(param_1 + 0x154) = uStack_4;
  *(undefined1 *)(param_1 + 0x26c) = local_5;
  *(int *)(param_1 + 0x100) = iVar2;
  *(undefined4 *)(param_1 + 0x104) = uVar3;
  *(char *)(param_1 + 0x158) = cStack_8;
  *(char *)(param_1 + 0x157) = cStack_7;
  *(undefined1 *)(param_1 + 0x28c) = uStack_6;
  if (cStack_7 == '\x02') {
    *(undefined1 *)(param_1 + 0x15b) = 3;
  }
  else if (cStack_7 == '\x04') {
    *(undefined1 *)(param_1 + 0x15b) = 2;
  }
  else if (cStack_7 == '\x06') {
    *(undefined1 *)(param_1 + 0x15b) = 4;
  }
  else {
    *(undefined1 *)(param_1 + 0x15b) = 1;
  }
  bVar1 = cStack_8 * *(char *)(param_1 + 0x15b);
  *(byte *)(param_1 + 0x15a) = bVar1;
  if (bVar1 < 8) {
    uVar4 = (uint)bVar1 * iVar2 + 7 >> 3;
  }
  else {
    uVar4 = (uint)(bVar1 >> 3) * iVar2;
  }
  *(uint *)(param_1 + 0x110) = uVar4;
  FUN_006720f0(param_1,param_2,iVar2,uVar3,cStack_8,cStack_7,uStack_4,uStack_6,local_5);
  return;
}

