
undefined8 FUN_004f9340(int param_1,undefined4 param_2)

{
  uint uVar1;
  longlong lVar2;
  longlong lVar3;
  int iVar4;
  void *_Memory;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  bool bVar8;
  int iVar9;
  int local_3c;
  uint local_34;
  int local_28;
  undefined4 local_24;
  undefined4 local_20;
  uint local_1c;
  uint local_18;
  undefined8 local_14;
  undefined8 local_c;
  
  local_34 = 0xffff;
  local_14._0_4_ = 0;
  local_14._4_4_ = 0;
  iVar4 = FUN_00401750(param_1,param_2,0,0,2);
  if (iVar4 == 0) {
    local_c = FUN_004017d0(param_1,param_2);
    if (((int)((ulonglong)local_c >> 0x20) == 0) && ((uint)local_c < 0xffff)) {
      local_34 = (uint)local_c;
    }
    _Memory = _malloc(0x404);
    if (_Memory == (void *)0x0) {
      local_24 = 0;
      local_20 = 0;
    }
    else {
      local_1c = 4;
      local_18 = 0;
      lVar2 = local_c;
      do {
        local_c._4_4_ = (uint)((ulonglong)lVar2 >> 0x20);
        local_c._0_4_ = (uint)lVar2;
        if ((local_18 != 0) || (local_34 <= local_1c)) break;
        if ((local_1c < 0xfffffc00) && (local_1c + 0x400 <= local_34)) {
          bVar8 = 0xfffffbff < local_1c;
          local_1c = local_1c + 0x400;
          local_18 = (uint)bVar8;
        }
        else {
          local_1c = local_34;
          local_18 = 0;
        }
        lVar3 = lVar2 - CONCAT44(local_18,local_1c);
        uVar5 = (uint)lVar3;
        uVar6 = (uint)((ulonglong)lVar3 >> 0x20);
        uVar7 = (uint)local_c - uVar5;
        uVar1 = local_c._4_4_ - uVar6;
        iVar4 = uVar1 - ((uint)local_c < uVar5);
        if (((local_c._4_4_ < uVar6 || uVar1 < ((uint)local_c < uVar5)) || iVar4 == 0) &&
           (uVar7 < 0x405)) {
          iVar9 = (uint)local_c - uVar5;
        }
        else {
          iVar9 = 0x404;
        }
        local_c = lVar2;
        iVar4 = FUN_00401750(param_1,param_2,lVar3,0,iVar9,uVar7,iVar4);
        lVar2 = local_c;
        if (iVar4 != 0) break;
        iVar4 = (**(code **)(param_1 + 4))(*(undefined4 *)(param_1 + 0x1c),param_2,_Memory,iVar9);
        lVar2 = local_c;
        if (iVar4 != iVar9) break;
        iVar4 = iVar9 + -3;
        do {
          local_3c = iVar4;
          iVar4 = local_3c + -1;
          if (local_3c < 1) goto LAB_004f9547;
        } while ((((*(char *)((int)_Memory + iVar4) != 'P') ||
                  (*(char *)((int)_Memory + local_3c) != 'K')) ||
                 (*(char *)((int)_Memory + local_3c + 1) != '\x06')) ||
                (*(char *)((int)_Memory + local_3c + 2) != '\a'));
        local_14 = lVar3 + iVar4;
LAB_004f9547:
      } while (local_14 == 0);
      local_c = lVar2;
      if (_Memory != (void *)0x0) {
        _free(_Memory);
      }
      if (local_14 == 0) {
        local_24 = 0;
        local_20 = 0;
      }
      else {
        iVar4 = FUN_00401750(param_1,param_2,local_14,0);
        if (iVar4 == 0) {
          iVar4 = FUN_004f8e60(param_1,param_2,&local_28);
          if (iVar4 == 0) {
            iVar4 = FUN_004f8e60(param_1,param_2,&local_28);
            if (iVar4 == 0) {
              if (local_28 == 0) {
                iVar4 = FUN_004f8f30(param_1,param_2,&local_24);
                if (iVar4 == 0) {
                  iVar4 = FUN_004f8e60(param_1,param_2,&local_28);
                  if (iVar4 == 0) {
                    if (local_28 == 1) {
                      iVar4 = FUN_00401750(param_1,param_2,local_24,local_20,0);
                      if (iVar4 == 0) {
                        iVar4 = FUN_004f8e60(param_1,param_2,&local_28);
                        if (iVar4 == 0) {
                          if (local_28 != 0x6064b50) {
                            local_24 = 0;
                            local_20 = 0;
                          }
                        }
                        else {
                          local_24 = 0;
                          local_20 = 0;
                        }
                      }
                      else {
                        local_24 = 0;
                        local_20 = 0;
                      }
                    }
                    else {
                      local_24 = 0;
                      local_20 = 0;
                    }
                  }
                  else {
                    local_24 = 0;
                    local_20 = 0;
                  }
                }
                else {
                  local_24 = 0;
                  local_20 = 0;
                }
              }
              else {
                local_24 = 0;
                local_20 = 0;
              }
            }
            else {
              local_24 = 0;
              local_20 = 0;
            }
          }
          else {
            local_24 = 0;
            local_20 = 0;
          }
        }
        else {
          local_24 = 0;
          local_20 = 0;
        }
      }
    }
  }
  else {
    local_24 = 0;
    local_20 = 0;
  }
  return CONCAT44(local_20,local_24);
}

