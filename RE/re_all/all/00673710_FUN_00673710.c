
void FUN_00673710(int param_1,int param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  byte bVar4;
  uint uVar5;
  
  iVar1 = param_1;
  if ((*(uint *)(param_1 + 0x74) & 1) == 0) {
    FUN_00668a30(param_1,s_missing_IHDR_00a0ce1c);
  }
  else if ((*(uint *)(param_1 + 0x74) & 6) != 0) {
    FUN_00673140(param_1,param_3);
    FUN_00668b90(iVar1,s_out_of_place_00a0cdb4);
    return;
  }
  uVar3 = param_3;
  if ((param_2 != 0) && ((*(byte *)(param_2 + 8) & 2) != 0)) {
    FUN_00673140(iVar1,param_3);
    FUN_00668b90(iVar1,s_duplicate_00a0bdf4);
    return;
  }
  if (*(char *)(iVar1 + 0x157) == '\x03') {
    uVar5 = 3;
    bVar4 = 8;
  }
  else {
    bVar4 = *(byte *)(iVar1 + 0x158);
    uVar5 = (uint)*(byte *)(iVar1 + 0x15b);
  }
  if ((param_3 == uVar5) && (param_3 < 5)) {
    param_1 = CONCAT31(CONCAT21(CONCAT11(bVar4,bVar4),bVar4),bVar4);
    FUN_00673110(iVar1,&param_1,uVar5);
    iVar2 = FUN_00673140(iVar1,0);
    if (iVar2 == 0) {
      uVar3 = 0;
      if (uVar5 != 0) {
        do {
          if ((*(byte *)((int)&param_1 + uVar3) == 0) || (bVar4 < *(byte *)((int)&param_1 + uVar3)))
          {
            FUN_00668b90(iVar1,s_invalid_00a0cdac);
            return;
          }
          uVar3 = uVar3 + 1;
        } while (uVar3 < uVar5);
      }
      if ((*(byte *)(iVar1 + 0x157) & 2) == 0) {
        *(undefined1 *)(iVar1 + 0x1ab) = (undefined1)param_1;
        *(undefined1 *)(iVar1 + 0x1a9) = (undefined1)param_1;
        *(undefined1 *)(iVar1 + 0x1aa) = (undefined1)param_1;
        *(undefined1 *)(iVar1 + 0x1a8) = (undefined1)param_1;
        *(undefined1 *)(iVar1 + 0x1ac) = param_1._1_1_;
        FUN_00672740(iVar1,param_2,(undefined1 *)(iVar1 + 0x1a8));
        return;
      }
      *(undefined1 *)(iVar1 + 0x1a9) = param_1._1_1_;
      *(undefined1 *)(iVar1 + 0x1ac) = param_1._3_1_;
      *(undefined1 *)(iVar1 + 0x1a8) = (undefined1)param_1;
      *(undefined1 *)(iVar1 + 0x1aa) = param_1._2_1_;
      FUN_00672740(iVar1,param_2,(undefined1 *)(iVar1 + 0x1a8));
      return;
    }
  }
  else {
    FUN_00668b90(iVar1,s_invalid_00a0cdac);
    FUN_00673140(iVar1,uVar3);
  }
  return;
}

