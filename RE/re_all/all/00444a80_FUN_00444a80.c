
undefined1 __thiscall FUN_00444a80(int param_1,int param_2)

{
  bool bVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  bool bVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  int local_c;
  undefined1 local_7;
  
  local_7 = 0;
  cVar2 = FUN_00486cd0();
  if (cVar2 == '\0') {
    for (local_c = 0; iVar3 = FUN_004d29a0(), local_c < iVar3; local_c = local_c + 1) {
      bVar1 = false;
      uVar6 = (uint)DAT_00a144f1;
      iVar3 = FUN_004d2a00(local_c);
      bVar7 = *(char *)(param_2 + *(int *)(iVar3 + 0x1e8)) != '\0';
      iVar3 = FUN_004d2a00(local_c);
      if (*(char *)(iVar3 + 0xb9) == '\0') {
LAB_00444b9a:
        iVar3 = FUN_004d2a00(local_c);
        uVar9 = 0;
        uVar8 = 1;
        FUN_004d2a00(local_c);
        iVar4 = FUN_004789a0(uVar8,uVar9);
        if ((int)((*(int *)(param_1 + 0x2c) - iVar4) - uVar6) <= *(int *)(iVar3 + 0x2c)) {
          iVar3 = FUN_004d2a00(local_c);
          uVar9 = 1;
          uVar8 = 1;
          FUN_004d2a00(local_c);
          iVar4 = FUN_004789a0(uVar8,uVar9);
          if (*(int *)(iVar3 + 0x2c) <= iVar4 + *(int *)(param_1 + 0x2c)) {
            bVar1 = true;
          }
        }
      }
      else {
        iVar3 = FUN_004d2a00(local_c);
        uVar9 = 0;
        uVar8 = 1;
        FUN_004d2a00(local_c);
        iVar4 = FUN_004789a0(uVar8,uVar9);
        if (*(int *)(iVar3 + 0x2c) < (int)((*(int *)(param_1 + 0x2c) - iVar4) - uVar6))
        goto LAB_00444b9a;
        iVar4 = FUN_004d2a00(local_c);
        iVar3 = *(int *)(param_1 + 0x2c);
        uVar9 = 1;
        uVar8 = 1;
        FUN_004d2a00(local_c);
        iVar5 = FUN_004789a0(uVar8,uVar9);
        if (iVar3 + 1 + iVar5 < *(int *)(iVar4 + 0x2c)) goto LAB_00444b9a;
        bVar1 = true;
      }
      iVar3 = FUN_004d2a00(local_c);
      if ((*(int *)(iVar3 + 0x1e8) < 4) && (bVar7)) {
        iVar3 = FUN_004d2a00(local_c);
        uVar9 = 0;
        uVar8 = 0;
        FUN_004d2a00(local_c);
        iVar4 = FUN_004789a0(uVar8,uVar9);
        if (*(int *)(param_1 + 0x28) - iVar4 <= *(int *)(iVar3 + 0x28)) {
          iVar3 = FUN_004d2a00(local_c);
          uVar9 = 0;
          uVar8 = 0;
          FUN_004d2a00(local_c);
          iVar4 = FUN_004789a0(uVar8,uVar9);
          if ((*(int *)(iVar3 + 0x28) <= iVar4 + *(int *)(param_1 + 0x28)) && (bVar1)) {
            FUN_004d2a00(local_c);
            cVar2 = FUN_00478410();
            if (cVar2 == '\0') {
              uVar8 = 0xffffffff;
              FUN_004d2a00(local_c);
              FUN_004799d0(uVar8);
              local_7 = 1;
            }
          }
        }
      }
      iVar3 = FUN_004d2a00(local_c);
      if ((*(int *)(iVar3 + 0x1e8) == 4) && (bVar7)) {
        iVar4 = FUN_004d2a00(local_c);
        iVar3 = *(int *)(param_1 + 0x28);
        uVar9 = 0;
        uVar8 = 0;
        FUN_004d2a00(local_c);
        iVar5 = FUN_004789a0(uVar8,uVar9);
        if ((iVar3 + -1) - iVar5 <= *(int *)(iVar4 + 0x28)) {
          iVar4 = FUN_004d2a00(local_c);
          iVar3 = *(int *)(param_1 + 0x28);
          uVar9 = 0;
          uVar8 = 0;
          FUN_004d2a00(local_c);
          iVar5 = FUN_004789a0(uVar8,uVar9);
          if ((*(int *)(iVar4 + 0x28) <= iVar3 + 1 + iVar5) && (bVar1)) {
            FUN_004d2a00(local_c);
            cVar2 = FUN_00478410();
            if (cVar2 == '\0') {
              uVar8 = 0xffffffff;
              FUN_004d2a00(local_c);
              FUN_004799d0(uVar8);
              local_7 = 1;
            }
          }
        }
      }
    }
  }
  else {
    local_7 = 0;
  }
  return local_7;
}

