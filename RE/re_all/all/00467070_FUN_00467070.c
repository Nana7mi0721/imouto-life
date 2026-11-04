
undefined4 FUN_00467070(void)

{
  uint *puVar1;
  undefined4 *puVar2;
  uint uVar3;
  undefined3 uVar9;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  int local_a8;
  int local_a4;
  int local_a0;
  int local_9c;
  int local_98;
  int local_94;
  int local_90;
  int local_8c;
  int local_88;
  int local_84;
  int local_80;
  int local_7c;
  int local_78;
  int local_74;
  int local_70;
  int local_6c;
  int local_68;
  int local_64;
  int local_60;
  int local_5c;
  int local_58;
  int local_54;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  int *local_38;
  int *local_34;
  int local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  int local_10;
  int local_c;
  int local_8;
  
  puVar1 = (uint *)FUN_004ce990(1);
  if ((*puVar1 & 0xf) == 0) {
    puVar2 = (undefined4 *)FUN_004ce990(3);
    local_c = FUN_00487080(*puVar2);
    puVar2 = (undefined4 *)FUN_004ce990(4);
    local_8 = FUN_00487080(*puVar2);
    puVar2 = (undefined4 *)FUN_004ce990(2);
    local_14 = FUN_00487080(*puVar2);
    puVar2 = (undefined4 *)FUN_004ce990(7);
    local_18 = FUN_00487080(*puVar2);
    puVar2 = (undefined4 *)FUN_004ce990(6);
    local_1c = FUN_00487080(*puVar2);
    puVar2 = (undefined4 *)FUN_004ce990(5);
    local_20 = FUN_00487080(*puVar2);
    puVar1 = (uint *)FUN_004ce990(1);
    local_24 = (int)(*puVar1 & 0xf0) >> 4;
    if (local_8 < local_c) {
      local_34 = &local_c;
    }
    else {
      local_34 = &local_8;
    }
    if (local_c < local_8) {
      local_38 = &local_c;
    }
    else {
      local_38 = &local_8;
    }
    uVar3 = FUN_004b8b80(local_38,local_34,&local_24,&local_20,&local_1c,&local_18,&local_14);
  }
  else {
    puVar1 = (uint *)FUN_004ce990(1);
    if ((*puVar1 & 0xf) == 1) {
      puVar2 = (undefined4 *)FUN_004ce990(3);
      local_10 = FUN_00452590(*puVar2);
      if (local_10 == 0) {
        uVar9 = 0;
        goto LAB_00467a78;
      }
      puVar1 = (uint *)FUN_004ce990(1);
      uVar3 = (int)(*puVar1 & 0xf0) >> 4;
      switch(uVar3) {
      case 0:
        puVar2 = (undefined4 *)FUN_004ce990(5);
        iVar4 = FUN_00487080(*puVar2);
        if (iVar4 < -100) {
          local_40 = -100;
        }
        else {
          puVar2 = (undefined4 *)FUN_004ce990(5);
          local_40 = FUN_00487080(*puVar2);
        }
        if (local_40 < 0x65) {
          puVar2 = (undefined4 *)FUN_004ce990(5);
          iVar4 = FUN_00487080(*puVar2);
          if (iVar4 < -100) {
            local_48 = -100;
          }
          else {
            puVar2 = (undefined4 *)FUN_004ce990(5);
            local_48 = FUN_00487080(*puVar2);
          }
          local_44 = local_48;
        }
        else {
          local_44 = 100;
        }
        puVar2 = (undefined4 *)FUN_004ce990(6);
        iVar4 = FUN_00487080(*puVar2);
        if (iVar4 < -100) {
          local_4c = -100;
        }
        else {
          puVar2 = (undefined4 *)FUN_004ce990(6);
          local_4c = FUN_00487080(*puVar2);
        }
        if (local_4c < 0x65) {
          puVar2 = (undefined4 *)FUN_004ce990(6);
          iVar4 = FUN_00487080(*puVar2);
          if (iVar4 < -100) {
            local_54 = -100;
          }
          else {
            puVar2 = (undefined4 *)FUN_004ce990(6);
            local_54 = FUN_00487080(*puVar2);
          }
          local_50 = local_54;
        }
        else {
          local_50 = 100;
        }
        puVar2 = (undefined4 *)FUN_004ce990(7);
        iVar4 = FUN_00487080(*puVar2);
        if (iVar4 < -100) {
          local_58 = -100;
        }
        else {
          puVar2 = (undefined4 *)FUN_004ce990(7);
          local_58 = FUN_00487080(*puVar2);
        }
        if (local_58 < 0x65) {
          puVar2 = (undefined4 *)FUN_004ce990(7);
          iVar4 = FUN_00487080(*puVar2);
          if (iVar4 < -100) {
            local_60 = -100;
          }
          else {
            puVar2 = (undefined4 *)FUN_004ce990(7);
            local_60 = FUN_00487080(*puVar2);
          }
          local_5c = local_60;
        }
        else {
          local_5c = 100;
        }
        puVar2 = (undefined4 *)FUN_004ce990(2);
        uVar5 = FUN_00487080(*puVar2);
        uVar3 = FUN_004b9d50((local_44 + 100) * 0x10000 + (local_50 + 100) * 0x100 + 100 + local_5c,
                             uVar5);
        break;
      case 1:
        puVar2 = (undefined4 *)FUN_004ce990(2);
        uVar5 = FUN_00487080(*puVar2);
        puVar2 = (undefined4 *)FUN_004ce990(7);
        uVar6 = FUN_00487080(*puVar2);
        puVar2 = (undefined4 *)FUN_004ce990(6);
        uVar7 = FUN_00487080(*puVar2);
        puVar2 = (undefined4 *)FUN_004ce990(5);
        uVar8 = FUN_00487080(*puVar2);
        uVar3 = FUN_004b9d90(uVar8,uVar7,uVar6,uVar5);
        break;
      case 2:
        puVar2 = (undefined4 *)FUN_004ce990(5);
        iVar4 = FUN_00487080(*puVar2);
        if (iVar4 < -100) {
          local_64 = -100;
        }
        else {
          puVar2 = (undefined4 *)FUN_004ce990(5);
          local_64 = FUN_00487080(*puVar2);
        }
        if (local_64 < 0x65) {
          puVar2 = (undefined4 *)FUN_004ce990(5);
          iVar4 = FUN_00487080(*puVar2);
          if (iVar4 < -100) {
            local_6c = -100;
          }
          else {
            puVar2 = (undefined4 *)FUN_004ce990(5);
            local_6c = FUN_00487080(*puVar2);
          }
          local_68 = local_6c;
        }
        else {
          local_68 = 100;
        }
        puVar2 = (undefined4 *)FUN_004ce990(6);
        iVar4 = FUN_00487080(*puVar2);
        if (iVar4 < -100) {
          local_70 = -100;
        }
        else {
          puVar2 = (undefined4 *)FUN_004ce990(6);
          local_70 = FUN_00487080(*puVar2);
        }
        if (local_70 < 0x65) {
          puVar2 = (undefined4 *)FUN_004ce990(6);
          iVar4 = FUN_00487080(*puVar2);
          if (iVar4 < -100) {
            local_78 = -100;
          }
          else {
            puVar2 = (undefined4 *)FUN_004ce990(6);
            local_78 = FUN_00487080(*puVar2);
          }
          local_74 = local_78;
        }
        else {
          local_74 = 100;
        }
        puVar2 = (undefined4 *)FUN_004ce990(7);
        iVar4 = FUN_00487080(*puVar2);
        if (iVar4 < -100) {
          local_7c = -100;
        }
        else {
          puVar2 = (undefined4 *)FUN_004ce990(7);
          local_7c = FUN_00487080(*puVar2);
        }
        if (local_7c < 0x65) {
          puVar2 = (undefined4 *)FUN_004ce990(7);
          iVar4 = FUN_00487080(*puVar2);
          if (iVar4 < -100) {
            local_84 = -100;
          }
          else {
            puVar2 = (undefined4 *)FUN_004ce990(7);
            local_84 = FUN_00487080(*puVar2);
          }
          local_80 = local_84;
        }
        else {
          local_80 = 100;
        }
        puVar2 = (undefined4 *)FUN_004ce990(2);
        uVar5 = FUN_00487080(*puVar2);
        uVar3 = FUN_004b9e10((local_68 + 100) * 0x10000 + (local_74 + 100) * 0x100 + 100 + local_80,
                             0,uVar5);
        break;
      case 3:
        puVar2 = (undefined4 *)FUN_004ce990(5);
        iVar4 = FUN_00487080(*puVar2);
        if (iVar4 < -100) {
          local_88 = -100;
        }
        else {
          puVar2 = (undefined4 *)FUN_004ce990(5);
          local_88 = FUN_00487080(*puVar2);
        }
        if (local_88 < 0x65) {
          puVar2 = (undefined4 *)FUN_004ce990(5);
          iVar4 = FUN_00487080(*puVar2);
          if (iVar4 < -100) {
            local_90 = -100;
          }
          else {
            puVar2 = (undefined4 *)FUN_004ce990(5);
            local_90 = FUN_00487080(*puVar2);
          }
          local_8c = local_90;
        }
        else {
          local_8c = 100;
        }
        puVar2 = (undefined4 *)FUN_004ce990(6);
        iVar4 = FUN_00487080(*puVar2);
        if (iVar4 < -100) {
          local_94 = -100;
        }
        else {
          puVar2 = (undefined4 *)FUN_004ce990(6);
          local_94 = FUN_00487080(*puVar2);
        }
        if (local_94 < 0x65) {
          puVar2 = (undefined4 *)FUN_004ce990(6);
          iVar4 = FUN_00487080(*puVar2);
          if (iVar4 < -100) {
            local_9c = -100;
          }
          else {
            puVar2 = (undefined4 *)FUN_004ce990(6);
            local_9c = FUN_00487080(*puVar2);
          }
          local_98 = local_9c;
        }
        else {
          local_98 = 100;
        }
        puVar2 = (undefined4 *)FUN_004ce990(7);
        iVar4 = FUN_00487080(*puVar2);
        if (iVar4 < -100) {
          local_a0 = -100;
        }
        else {
          puVar2 = (undefined4 *)FUN_004ce990(7);
          local_a0 = FUN_00487080(*puVar2);
        }
        if (local_a0 < 0x65) {
          puVar2 = (undefined4 *)FUN_004ce990(7);
          iVar4 = FUN_00487080(*puVar2);
          if (iVar4 < -100) {
            local_a8 = -100;
          }
          else {
            puVar2 = (undefined4 *)FUN_004ce990(7);
            local_a8 = FUN_00487080(*puVar2);
          }
          local_a4 = local_a8;
        }
        else {
          local_a4 = 100;
        }
        puVar2 = (undefined4 *)FUN_004ce990(2);
        uVar5 = FUN_00487080(*puVar2);
        uVar3 = FUN_004b9e10((local_8c + 100) * 0x10000 + (local_98 + 100) * 0x100 + 100 + local_a4,
                             1,uVar5);
      }
    }
    else {
      puVar1 = (uint *)FUN_004ce990(1);
      uVar3 = *puVar1 & 0xf;
      if (uVar3 == 2) {
        puVar1 = (uint *)FUN_004ce990(1);
        uVar3 = (int)(*puVar1 & 0xf0) >> 4;
        if (uVar3 == 0) {
          puVar2 = (undefined4 *)FUN_004ce990(2);
          uVar5 = FUN_00487080(*puVar2);
          puVar2 = (undefined4 *)FUN_004ce990(7);
          uVar6 = FUN_00487080(*puVar2);
          puVar2 = (undefined4 *)FUN_004ce990(6);
          uVar7 = FUN_00487080(*puVar2);
          puVar2 = (undefined4 *)FUN_004ce990(5);
          uVar8 = FUN_00487080(*puVar2);
          uVar3 = FUN_0044b2c0(uVar8,uVar7,uVar6,uVar5);
        }
      }
    }
  }
  uVar9 = (undefined3)(uVar3 >> 8);
LAB_00467a78:
  return CONCAT31(uVar9,1);
}

