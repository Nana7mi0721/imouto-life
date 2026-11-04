
undefined4 __thiscall FUN_0047dcf0(undefined4 param_1,char param_2)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  uint uVar6;
  undefined1 local_44 [4];
  undefined1 local_40 [4];
  uint local_3c;
  int local_38;
  char local_31;
  int local_30;
  undefined1 local_1c [4];
  int local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007af2a8;
  local_10 = ExceptionList;
  local_14 = 0;
  ExceptionList = &local_10;
  do {
    if (2 < local_14) {
      if (param_2 != '\0') {
        FUN_00550c60(0,param_1);
        FUN_004ccc40();
        FUN_004ccc40();
      }
      ExceptionList = local_10;
      return 1;
    }
    local_18 = 0;
    while (iVar2 = FUN_004717c0(local_14 + 1), local_18 < iVar2) {
      iVar2 = FUN_004cc130();
      if (local_18 < iVar2) {
        piVar3 = (int *)FUN_004cc020(&local_18);
        local_30 = *piVar3;
        if (param_2 == '\0') {
          iVar2 = FUN_00560f10(local_30);
          if ((iVar2 == 0) && (local_30 != 0)) {
            if (local_14 == 2) {
              local_31 = '\0';
              local_38 = 0;
              while (iVar2 = FUN_004ce080(), local_38 < iVar2) {
                piVar3 = (int *)FUN_004ce990(local_38);
                if (*piVar3 == local_30) {
                  local_31 = '\x01';
                  break;
                }
                local_38 = local_38 + 1;
              }
              if (local_31 != '\0') goto LAB_0047dd33;
            }
LAB_0047de0e:
            FUN_00515700(local_30,0);
            uVar4 = FUN_004cc020(&local_18);
            puVar5 = (undefined4 *)FUN_004cc020(uVar4);
            *puVar5 = 0;
            puVar5 = (undefined4 *)FUN_004cc020(&local_18);
            *puVar5 = 0;
            FUN_004cc870(local_1c);
            FUN_004cc150();
            local_8 = 0;
            while( true ) {
              uVar4 = FUN_004ce060(local_40);
              cVar1 = const_iterator__operator__(uVar4);
              if (cVar1 == '\0') break;
              iVar2 = FUN_004d07e0();
              if (*(int *)(iVar2 + 0x1c) == local_30) {
                uVar4 = FUN_004d07e0();
                FUN_004cc500(uVar4);
              }
              FUN_004e9550(local_44,0);
            }
            local_3c = 0;
            while (uVar6 = FUN_004cc430(), local_3c < uVar6) {
              uVar4 = FUN_004cc4c0(local_3c);
              FUN_004ccbe0(uVar4);
              local_3c = local_3c + 1;
            }
            local_8 = 0xffffffff;
            FUN_004cc250();
          }
        }
        else if (local_30 != 0) goto LAB_0047de0e;
      }
LAB_0047dd33:
      local_18 = local_18 + 1;
    }
    local_14 = local_14 + 1;
  } while( true );
}

