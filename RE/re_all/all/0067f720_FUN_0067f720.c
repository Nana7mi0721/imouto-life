
void FUN_0067f720(int *param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  
  iVar3 = 0;
  if (param_1[0x21] < 1) {
    uVar5 = param_3 + 5;
  }
  else {
    if (*(int *)(*param_1 + 0x2c) == 2) {
      uVar4 = FUN_00680c90(param_1);
      *(undefined4 *)(*param_1 + 0x2c) = uVar4;
    }
    FUN_0067f930(param_1,param_1 + 0x2c6);
    FUN_0067f930(param_1,param_1 + 0x2c9);
    iVar3 = FUN_0067ff00(param_1);
    uVar6 = param_1[0x5aa] + 10U >> 3;
    uVar5 = param_1[0x5ab] + 10U >> 3;
    if (uVar6 < uVar5) goto LAB_0067f794;
  }
  uVar6 = uVar5;
LAB_0067f794:
  if ((uVar6 < param_3 + 4U) || (param_2 == 0)) {
    if ((param_1[0x22] == 4) || (uVar5 == uVar6)) {
      iVar1 = param_1[0x5af];
      iVar3 = param_4 + 2;
      if (iVar1 < 0xe) {
        *(ushort *)(param_1 + 0x5ae) =
             *(ushort *)(param_1 + 0x5ae) | (ushort)(iVar3 << ((byte)iVar1 & 0x1f));
        param_1[0x5af] = iVar1 + 3;
      }
      else {
        *(ushort *)(param_1 + 0x5ae) =
             *(ushort *)(param_1 + 0x5ae) | (ushort)(iVar3 << ((byte)iVar1 & 0x1f));
        *(char *)(param_1[5] + param_1[2]) = (char)param_1[0x5ae];
        iVar1 = param_1[5];
        param_1[5] = iVar1 + 1;
        *(undefined1 *)(iVar1 + 1 + param_1[2]) = *(undefined1 *)((int)param_1 + 0x16b9);
        iVar1 = param_1[0x5af];
        param_1[5] = param_1[5] + 1;
        param_1[0x5af] = iVar1 + -0xd;
        *(ushort *)(param_1 + 0x5ae) = (ushort)iVar3 >> (0x10U - (char)iVar1 & 0x1f);
      }
      FUN_00680850(param_1,&DAT_00821d6c,&DAT_008221ec);
    }
    else {
      iVar2 = param_1[0x5af];
      iVar1 = param_4 + 4;
      if (iVar2 < 0xe) {
        *(ushort *)(param_1 + 0x5ae) =
             *(ushort *)(param_1 + 0x5ae) | (ushort)(iVar1 << ((byte)iVar2 & 0x1f));
        param_1[0x5af] = iVar2 + 3;
      }
      else {
        *(ushort *)(param_1 + 0x5ae) =
             *(ushort *)(param_1 + 0x5ae) | (ushort)(iVar1 << ((byte)iVar2 & 0x1f));
        *(char *)(param_1[2] + param_1[5]) = (char)param_1[0x5ae];
        iVar2 = param_1[5];
        param_1[5] = iVar2 + 1;
        *(undefined1 *)(iVar2 + 1 + param_1[2]) = *(undefined1 *)((int)param_1 + 0x16b9);
        iVar2 = param_1[0x5af];
        param_1[5] = param_1[5] + 1;
        param_1[0x5af] = iVar2 + -0xd;
        *(ushort *)(param_1 + 0x5ae) = (ushort)iVar1 >> (0x10U - (char)iVar2 & 0x1f);
      }
      FUN_00680060(param_1,param_1[0x2c7] + 1,param_1[0x2ca] + 1,iVar3 + 1);
      FUN_00680850(param_1,param_1 + 0x25,param_1 + 0x262);
    }
  }
  else {
    FUN_0067f530(param_1,param_2,param_3,param_4);
  }
  FUN_0067f4c0(param_1);
  if (param_4 != 0) {
    FUN_00680db0(param_1);
  }
  return;
}

