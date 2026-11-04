
undefined4
FUN_0066a2d0(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            )

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 local_dc [24];
  undefined1 local_c4 [6];
  undefined1 auStack_be [190];
  
  if (param_2 != 0) {
    *(byte *)(param_2 + 0x4b) = *(byte *)(param_2 + 0x4b) | 0x80;
  }
  iVar1 = FUN_00668650(local_c4,0xc4,0,s_profile___00a0bf3c);
  uVar2 = FUN_00668650(local_c4,iVar1 + 0x4f,iVar1,param_3);
  iVar3 = FUN_00668650(local_c4,0xc4,uVar2,&DAT_00a0bf38);
  iVar1 = FUN_0066a450(param_4);
  if (iVar1 == 0) {
    uVar2 = FUN_00668690(local_dc,local_c4,3,param_4);
    uVar2 = FUN_00668650(local_c4,0xc4,iVar3,uVar2);
    iVar3 = FUN_00668650(local_c4,0xc4,uVar2,&DAT_00a0bf34);
  }
  else {
    FUN_0066a3e0(local_c4 + iVar3);
    auStack_be[iVar3] = 0x3a;
    auStack_be[iVar3 + 1] = 0x20;
    iVar3 = iVar3 + 8;
  }
  FUN_00668650(local_c4,0xc4,iVar3,param_5);
  FUN_00668bc0(param_1,local_c4,(param_2 != 0) + '\x01');
  return 0;
}

