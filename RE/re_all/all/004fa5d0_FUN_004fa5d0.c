
int FUN_004fa5d0(int *param_1,int *param_2,undefined4 *param_3,int param_4,int param_5)

{
  int iVar1;
  void *pvVar2;
  uint uVar3;
  uint uVar4;
  int *piVar5;
  int *piVar6;
  int local_24;
  int local_20;
  int local_18;
  uint local_14;
  int *local_10;
  int local_c;
  int *local_8;
  
  local_18 = 0;
  if (param_5 == 0) {
    if (param_1 == (int *)0x0) {
      iVar1 = -0x66;
    }
    else {
      local_8 = param_1;
      if (param_1[0x18] == 0 && param_1[0x19] == 0) {
        iVar1 = -0x66;
      }
      else {
        if (param_1[0x38] != 0) {
          FUN_004fb420(param_1);
        }
        iVar1 = FUN_004fa940(local_8,&local_14,&local_24,&local_c);
        if (iVar1 == 0) {
          local_10 = _malloc(0xd0);
          if (local_10 == (int *)0x0) {
            iVar1 = -0x68;
          }
          else {
            pvVar2 = _malloc(0x4000);
            *local_10 = (int)pvVar2;
            local_10[0x14] = local_24;
            local_10[0x15] = local_20;
            local_10[0x16] = local_c;
            local_10[0x18] = 0;
            local_10[0x19] = 0;
            local_10[0x32] = param_4;
            if (*local_10 == 0) {
              if (local_10 != (int *)0x0) {
                _free(local_10);
              }
              iVar1 = -0x68;
            }
            else {
              local_10[0x12] = 0;
              if (param_2 != (int *)0x0) {
                *param_2 = local_8[0x23];
              }
              if (param_3 != (undefined4 *)0x0) {
                *param_3 = 6;
                uVar3 = local_8[0x22] & 6;
                if (uVar3 == 2) {
                  *param_3 = 9;
                }
                else if (uVar3 == 4) {
                  *param_3 = 2;
                }
                else if (uVar3 == 6) {
                  *param_3 = 1;
                }
              }
              if (((local_8[0x23] != 0) && (local_8[0x23] != 0xc)) && (local_8[0x23] != 8)) {
                local_18 = 0xffffff99;
              }
              local_10[0x1d] = local_8[0x25];
              local_10[0x1c] = 0;
              local_10[0x1a] = 0;
              local_10[0x1b] = 0;
              local_10[0x2e] = local_8[0x23];
              local_10[0x2d] = local_8[0xc];
              piVar5 = local_8;
              piVar6 = local_10 + 0x22;
              for (iVar1 = 0xb; iVar1 != 0; iVar1 = iVar1 + -1) {
                *piVar6 = *piVar5;
                piVar5 = piVar5 + 1;
                piVar6 = piVar6 + 1;
              }
              local_10[0x30] = local_8[0x12];
              local_10[0x31] = local_8[0x13];
              local_10[6] = 0;
              if ((local_8[0x23] == 0xc) && (param_4 == 0)) {
                local_10[0x32] = 1;
              }
              else if ((local_8[0x23] == 8) && (param_4 == 0)) {
                local_10[9] = 0;
                local_10[10] = 0;
                local_10[0xb] = 0;
                local_10[1] = 0;
                local_10[2] = 0;
                local_18 = FUN_0067aae0(local_10 + 1,0xfffffff1,s_1_2_5_0084b46c,0x38);
                if (local_18 != 0) {
                  if (local_10 != (int *)0x0) {
                    _free(local_10);
                  }
                  return local_18;
                }
                local_10[0x12] = 8;
              }
              local_10[0x1e] = local_8[0x26];
              local_10[0x1f] = local_8[0x27];
              local_10[0x20] = local_8[0x28];
              local_10[0x21] = local_8[0x29];
              uVar3 = local_8[0x36];
              uVar4 = uVar3 + 0x1e;
              iVar1 = local_8[0x37];
              local_10[0x10] = uVar4 + local_14;
              local_10[0x11] = iVar1 + (uint)(0xffffffe1 < uVar3) + (uint)CARRY4(uVar4,local_14);
              local_10[2] = 0;
              local_8[0x38] = (int)local_10;
              local_8[0x39] = 0;
              iVar1 = 0;
            }
          }
        }
        else {
          iVar1 = -0x67;
        }
      }
    }
  }
  else {
    iVar1 = -0x66;
  }
  return iVar1;
}

