
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FUN_004fa2c0(int param_1,char *param_2,undefined4 param_3)

{
  size_t sVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined1 local_18c [264];
  undefined4 local_84;
  int local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  int local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c [22];
  
  local_84 = DAT_0084b484;
  if (param_1 == 0) {
    local_80 = -0x66;
  }
  else {
    sVar1 = _strlen(param_2);
    if (sVar1 < 0x100) {
      local_68 = param_1;
      if (*(int *)(param_1 + 0x60) == 0 && *(int *)(param_1 + 100) == 0) {
        local_80 = -100;
      }
      else {
        local_7c = *(undefined4 *)(param_1 + 0x50);
        local_78 = *(undefined4 *)(param_1 + 0x54);
        local_64 = *(undefined4 *)(param_1 + 0x58);
        local_60 = *(undefined4 *)(param_1 + 0x5c);
        puVar3 = (undefined4 *)(param_1 + 0x80);
        puVar4 = local_5c;
        for (iVar2 = 0x16; iVar2 != 0; iVar2 = iVar2 + -1) {
          *puVar4 = *puVar3;
          puVar3 = puVar3 + 1;
          puVar4 = puVar4 + 1;
        }
        local_74 = *(undefined4 *)(param_1 + 0xd8);
        local_70 = *(undefined4 *)(param_1 + 0xdc);
        local_80 = FUN_004fa100(param_1);
        while (local_80 == 0) {
          local_80 = FUN_004f9820(param_1,0,local_18c,0x100,0,0,0,0);
          if (local_80 == 0) {
            iVar2 = FUN_004f8670(local_18c,param_2,param_3);
            if (iVar2 == 0) {
              return 0;
            }
            local_80 = FUN_004fa190(param_1);
          }
        }
        *(undefined4 *)(local_68 + 0x50) = local_7c;
        *(undefined4 *)(local_68 + 0x54) = local_78;
        *(undefined4 *)(local_68 + 0x58) = local_64;
        *(undefined4 *)(local_68 + 0x5c) = local_60;
        puVar3 = local_5c;
        puVar4 = (undefined4 *)(local_68 + 0x80);
        for (iVar2 = 0x16; iVar2 != 0; iVar2 = iVar2 + -1) {
          *puVar4 = *puVar3;
          puVar3 = puVar3 + 1;
          puVar4 = puVar4 + 1;
        }
        *(undefined4 *)(local_68 + 0xd8) = local_74;
        *(undefined4 *)(local_68 + 0xdc) = local_70;
      }
    }
    else {
      local_80 = -0x66;
    }
  }
  return local_80;
}

