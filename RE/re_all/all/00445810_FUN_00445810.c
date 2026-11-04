
undefined1 FUN_00445810(int param_1,int param_2)

{
  bool bVar1;
  bool bVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  int local_c;
  undefined1 local_7;
  
  local_7 = 0;
  cVar3 = FUN_00486cd0();
  if (cVar3 == '\0') {
    for (local_c = 0; iVar4 = FUN_004d29a0(), local_c < iVar4; local_c = local_c + 1) {
      bVar2 = false;
      uVar6 = (uint)DAT_00a144f1;
      iVar4 = FUN_004d2a00(local_c);
      if (*(char *)(iVar4 + 0xb9) == '\0') {
LAB_004458fd:
        iVar4 = FUN_004d2a00(local_c);
        uVar8 = 0;
        uVar7 = 1;
        FUN_004d2a00(local_c);
        iVar5 = FUN_004789a0(uVar7,uVar8);
        if ((int)((param_2 - iVar5) - uVar6) <= *(int *)(iVar4 + 0x2c)) {
          iVar4 = FUN_004d2a00(local_c);
          uVar8 = 1;
          uVar7 = 1;
          FUN_004d2a00(local_c);
          iVar5 = FUN_004789a0(uVar7,uVar8);
          if (*(int *)(iVar4 + 0x2c) <= iVar5 + param_2) {
            bVar2 = true;
          }
        }
      }
      else {
        iVar4 = FUN_004d2a00(local_c);
        uVar8 = 0;
        uVar7 = 1;
        FUN_004d2a00(local_c);
        iVar5 = FUN_004789a0(uVar7,uVar8);
        if (*(int *)(iVar4 + 0x2c) < (int)((param_2 - iVar5) - uVar6)) goto LAB_004458fd;
        iVar4 = FUN_004d2a00(local_c);
        uVar8 = 1;
        uVar7 = 1;
        FUN_004d2a00(local_c);
        iVar5 = FUN_004789a0(uVar7,uVar8);
        if (param_2 + 1 + iVar5 < *(int *)(iVar4 + 0x2c)) goto LAB_004458fd;
        bVar2 = true;
      }
      bVar1 = false;
      iVar4 = FUN_004d2a00(local_c);
      if ((*(int *)(iVar4 + 0x1e8) == 3) ||
         (iVar4 = FUN_004d2a00(local_c), *(int *)(iVar4 + 0x1e8) == 4)) {
        bVar1 = true;
      }
      if (bVar1) {
        iVar4 = FUN_004d2a00(local_c);
        uVar8 = 0;
        uVar7 = 0;
        FUN_004d2a00(local_c);
        iVar5 = FUN_004789a0(uVar7,uVar8);
        if ((param_1 + -1) - iVar5 <= *(int *)(iVar4 + 0x28)) {
          iVar4 = FUN_004d2a00(local_c);
          uVar8 = 0;
          uVar7 = 0;
          FUN_004d2a00(local_c);
          iVar5 = FUN_004789a0(uVar7,uVar8);
          if ((*(int *)(iVar4 + 0x28) <= param_1 + 1 + iVar5) && (bVar2)) {
            FUN_004d2a00(local_c);
            cVar3 = FUN_00478410();
            if (cVar3 == '\0') {
              FUN_004d2a00(local_c);
              cVar3 = FUN_00446ea0();
              if (cVar3 == '\0') {
                uVar7 = 0xffffffff;
                FUN_004d2a00(local_c);
                FUN_004799d0(uVar7);
                local_7 = 1;
              }
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

