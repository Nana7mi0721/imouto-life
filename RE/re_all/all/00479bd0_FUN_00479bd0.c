
void __fastcall FUN_00479bd0(int param_1)

{
  int iVar1;
  bool bVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  
  if (*(int *)(param_1 + 0x1e8) == 4) {
    cVar3 = FUN_00486cd0();
    if (cVar3 == '\0') {
      bVar2 = false;
      uVar6 = (uint)DAT_00a144f1;
      iVar1 = *(int *)(param_1 + 0x28);
      iVar5 = *(int *)(param_1 + 0x2c);
      iVar4 = FUN_004789a0(1,0);
      if ((int)((iVar5 - iVar4) - uVar6) <= DAT_00a14464) {
        iVar7 = DAT_00a14464 - (~-(uint)(*(char *)(param_1 + 0xb9) != '\0') & uVar6);
        iVar4 = FUN_004789a0(1,1);
        if (iVar7 <= iVar4 + iVar5) {
          bVar2 = true;
        }
      }
      if (bVar2) {
        iVar5 = FUN_004789a0(0,0);
        if ((iVar1 + -1) - iVar5 <= DAT_00a14460) {
          iVar5 = FUN_004789a0(0,0);
          if (DAT_00a14460 <= iVar1 + 1 + iVar5) {
            cVar3 = FUN_00478410();
            if (cVar3 == '\0') {
              cVar3 = FUN_00446ea0();
              if (cVar3 != '\0') {
                FUN_004799d0(0xffffffff);
              }
            }
          }
        }
      }
    }
  }
  if (*(int *)(param_1 + 0x1e8) == 1) {
    FUN_004799d0(0xffffffff);
  }
  return;
}

