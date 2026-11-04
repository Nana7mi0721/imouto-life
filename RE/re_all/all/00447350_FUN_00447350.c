
void __thiscall FUN_00447350(int param_1,int param_2,int param_3)

{
  bool bVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  
  cVar2 = FUN_00486cd0();
  if (cVar2 == '\0') {
    bVar1 = false;
    iVar3 = FUN_0046f600(*(undefined4 *)(param_1 + 0x24));
    uVar4 = (uint)DAT_00a144f1;
    if (iVar3 != -1) {
      uVar8 = 0;
      uVar7 = 1;
      FUN_004d2a00(iVar3);
      iVar5 = FUN_004789a0(uVar7,uVar8);
      if ((int)((param_3 - iVar5) - uVar4) <= DAT_00a14464) {
        iVar6 = DAT_00a14464 - (~-(uint)(*(char *)(param_1 + 0xb9) != '\0') & uVar4);
        uVar8 = 1;
        uVar7 = 1;
        FUN_004d2a00(iVar3);
        iVar5 = FUN_004789a0(uVar7,uVar8);
        if (iVar6 <= iVar5 + param_3) {
          bVar1 = true;
        }
      }
      if ((*(int *)(param_1 + 0x1e8) == 4) && (bVar1)) {
        uVar8 = 0;
        uVar7 = 0;
        FUN_004d2a00(iVar3);
        iVar5 = FUN_004789a0(uVar7,uVar8);
        if ((param_2 + -1) - iVar5 <= DAT_00a14460) {
          uVar8 = 0;
          uVar7 = 0;
          FUN_004d2a00(iVar3);
          iVar3 = FUN_004789a0(uVar7,uVar8);
          if (((DAT_00a14460 <= param_2 + 1 + iVar3) && (cVar2 = FUN_00478410(), cVar2 == '\0')) &&
             (cVar2 = FUN_00446ea0(), cVar2 == '\0')) {
            FUN_004799d0(0xffffffff);
          }
        }
      }
    }
  }
  return;
}

