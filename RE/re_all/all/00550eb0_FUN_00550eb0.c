
void FUN_00550eb0(int param_1,int param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  
  do {
    if (param_3 == 0) {
      return;
    }
    uVar1 = *(uint *)(param_2 + 0x1c);
    uVar3 = param_3;
    if (uVar1 == 0) {
      uVar1 = *(uint *)(param_2 + 0x20);
      if (uVar1 == 0) {
        return;
      }
      if (uVar1 < param_3) {
        uVar3 = uVar1;
      }
      if (*(short *)(param_1 + 0x1202) == 8) {
        uVar4 = 0x7f;
      }
      else {
        uVar4 = 0;
      }
      FUN_0056d380(*(int *)(param_2 + 8) + *(int *)(param_2 + 0x18),uVar4,uVar3);
      *(int *)(param_2 + 0x20) = *(int *)(param_2 + 0x20) - uVar3;
      *(int *)(param_2 + 0x18) = *(int *)(param_2 + 0x18) + uVar3;
    }
    else {
      iVar2 = *(int *)(param_2 + 4) + *(int *)(param_2 + 0x14);
      if (uVar1 < param_3) {
        uVar3 = uVar1;
      }
      if (*(short *)(param_1 + 0x1202) == 8) {
        FUN_0056d380(iVar2,0x7f,uVar3);
        *(int *)(param_2 + 0x1c) = *(int *)(param_2 + 0x1c) - uVar3;
        *(int *)(param_2 + 0x14) = *(int *)(param_2 + 0x14) + uVar3;
      }
      else {
        FUN_0056d380(iVar2,0,uVar3);
        *(int *)(param_2 + 0x1c) = *(int *)(param_2 + 0x1c) - uVar3;
        *(int *)(param_2 + 0x14) = *(int *)(param_2 + 0x14) + uVar3;
      }
    }
    param_3 = param_3 - uVar3;
  } while( true );
}

