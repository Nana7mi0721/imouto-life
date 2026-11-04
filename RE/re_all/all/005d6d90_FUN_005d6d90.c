
undefined4 * __thiscall
FUN_005d6d90(uint param_1,undefined4 *param_2,undefined4 *param_3,undefined4 param_4,int param_5,
            int param_6,int param_7,int param_8,int param_9)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  byte bVar3;
  int in_EAX;
  int iVar4;
  uint uVar5;
  undefined4 *puVar6;
  char *pcVar7;
  undefined4 *local_c;
  undefined4 *local_4;
  
  if ((*(int *)(in_EAX + 0x2c) != 0) && (*(int *)(in_EAX + 0x3c) == 0)) {
    return (undefined4 *)0x0;
  }
  *(int *)(in_EAX + 100) = *(int *)(in_EAX + 100) + 1;
  *(int *)(param_2[0x11] + 0x18) = *(int *)(param_2[0x11] + 0x18) + 1;
  if ((*(int *)(in_EAX + 0x1c) == 0) && (param_6 != 0)) {
    iVar4 = *(int *)(in_EAX + 0x2c);
    if (iVar4 == 0) {
      local_4 = (undefined4 *)(((uint)(param_3 + -0x17) / param_1) * param_1);
      uVar5 = (int)local_4 - (int)param_2;
LAB_005d6e15:
      if (0x8f < uVar5) {
LAB_005d6e21:
        if (iVar4 == 0) {
          local_c = local_4;
        }
        else {
          local_c = *(undefined4 **)(in_EAX + 0x3c);
          FUN_005d6ad0();
          local_c[9] = param_3;
        }
        *(undefined1 *)((int)local_c + 0x16) = 0;
        FUN_005d6970(1,param_8,param_9);
        uVar2 = param_2[0x11];
        *(byte *)((int)local_c + 0x16) = *(byte *)((int)local_c + 0x16) | 0x10;
        local_c[0x11] = uVar2;
        if ((*(byte *)((int)param_2 + 0x16) & 8) == 0) {
          bVar3 = *(byte *)((int)local_c + 0x16) & 0xf7;
        }
        else {
          bVar3 = *(byte *)((int)local_c + 0x16) | 8;
        }
        *(byte *)((int)local_c + 0x16) = bVar3;
        *(byte *)((int)param_2 + 0x16) = *(byte *)((int)param_2 + 0x16) | 8;
        if (*(int *)(in_EAX + 0x2c) == 0) {
          local_c[8] = (param_2[8] - (int)local_c) + (int)param_2;
          FUN_005d6a40();
        }
        else {
          local_c[8] = (param_2[9] - (int)param_3) + param_2[8];
        }
        local_c[0xc] = param_2;
        local_c[0xd] = param_2[0xd];
        param_2[0xd] = local_c;
        if (local_c[0xd] == 0) {
          *(undefined4 **)(in_EAX + 0x60) = local_c;
        }
        else {
          *(undefined4 **)(local_c[0xd] + 0x30) = local_c;
        }
        FUN_005d6b50();
        if (*(int *)(in_EAX + 0x2c) == 0) {
          param_2[8] = (int)local_4 - (int)param_2;
          FUN_005d6a40();
        }
        else {
          param_2[8] = uVar5;
        }
        *(int *)(in_EAX + 0x58) = *(int *)(in_EAX + 0x58) - local_c[8];
        *(int *)(in_EAX + 0x68) = *(int *)(in_EAX + 0x68) + local_c[8];
        local_c[0xb] = param_4;
        local_c[10] = param_3;
        if (*(int *)(in_EAX + 0x2c) == 0) {
          param_3[-1] = (int)param_3 - (int)local_c;
          return param_3;
        }
        return local_c;
      }
    }
    else {
      uVar5 = (int)param_3 - param_2[9];
      if (0xf < uVar5) goto LAB_005d6e21;
      if (iVar4 == 0) goto LAB_005d6e15;
    }
    param_2[0xb] = param_4;
    param_2[10] = param_3;
    if (*(int *)(in_EAX + 0x2c) == 0) {
      local_c = param_3;
      param_3[-1] = (int)param_3 - (int)param_2;
    }
    else {
      local_c = param_2;
    }
    FUN_005d6bd0();
    FUN_005d6970(1,param_8,param_9);
    FUN_005d6b50();
  }
  else {
    param_2[0xb] = param_4;
    param_2[10] = param_3;
    if (*(int *)(in_EAX + 0x2c) == 0) {
      local_c = param_3;
      param_3[-1] = (int)param_3 - (int)param_2;
    }
    else {
      local_c = param_2;
    }
    if (*(int *)(in_EAX + 0x1c) == 0) {
      FUN_005d6bd0();
    }
    else if (*(int *)(in_EAX + 0x1c) == 1) {
      FUN_005d6ce0();
    }
    *(byte *)((int)param_2 + 0x16) = *(byte *)((int)param_2 + 0x16) | 4;
    *param_2 = 0x4d454d44;
    if (param_9 == 0) {
      bVar3 = *(byte *)((int)param_2 + 0x16) & 0xdf;
    }
    else {
      bVar3 = *(byte *)((int)param_2 + 0x16) | 0x20;
    }
    *(byte *)((int)param_2 + 0x16) = bVar3;
    if (param_7 == 0) {
      pcVar7 = "NoName";
    }
    else {
      iVar4 = FUN_005773c0(0x7ffd,param_7);
      if (iVar4 < 0x11) {
        iVar4 = 0;
      }
      else {
        iVar4 = iVar4 + -0x11;
      }
      pcVar7 = (char *)(iVar4 + param_7);
    }
    FUN_00576e80(0x7ffd,param_2 + 1,pcVar7);
    if (param_8 < 0) {
      param_8 = 0;
    }
    *(short *)((int)param_2 + 0x1e) = (short)param_8;
    *(byte *)((int)param_2 + 0x16) =
         (byte)((uint)param_8 >> 0x10) | *(byte *)((int)param_2 + 0x16) & 0xfc;
    param_2[0x10] = in_EAX;
    *(undefined1 *)((int)param_2 + 0x19) = *(undefined1 *)(in_EAX + 0x26);
    *(undefined2 *)((int)param_2 + 0x1a) = *(undefined2 *)(in_EAX + 0x24);
    *(int *)(in_EAX + 0x24) = *(int *)(in_EAX + 0x24) + 1;
    if (0xffffff < *(uint *)(in_EAX + 0x24)) {
      *(undefined4 *)(in_EAX + 0x24) = 0;
    }
    *(undefined2 *)(param_2 + 7) = *(undefined2 *)(in_EAX + 0x28);
    FUN_005d6b50();
    iVar4 = *(int *)(in_EAX + 0x2c);
    if (iVar4 == 0) {
      local_4 = (undefined4 *)((int)param_3 + param_5 + 0x1f & 0xfffffff0);
      uVar5 = (param_2[8] - (int)local_4) + (int)param_2;
LAB_005d70ee:
      if (0x8f < uVar5) {
LAB_005d70fa:
        puVar6 = local_4;
        if (iVar4 != 0) {
          puVar6 = *(undefined4 **)(in_EAX + 0x3c);
          FUN_005d6ad0();
          puVar6[9] = (int)param_3 + param_5;
        }
        *puVar6 = 0x4d454d44;
        *(undefined1 *)((int)puVar6 + 0x16) = 0;
        iVar4 = FUN_005773c0(0x7ffd,&DAT_007fffa0);
        if (iVar4 < 0x11) {
          iVar4 = 0;
        }
        else {
          iVar4 = iVar4 + -0x11;
        }
        FUN_00576e80(0x7ffd,puVar6 + 1,&DAT_007fffa0 + iVar4);
        *(byte *)((int)puVar6 + 0x16) = *(byte *)((int)puVar6 + 0x16) & 0xfc;
        *(undefined2 *)((int)puVar6 + 0x1e) = 0;
        puVar6[0x10] = in_EAX;
        *(undefined1 *)((int)puVar6 + 0x19) = *(undefined1 *)(in_EAX + 0x26);
        *(undefined2 *)((int)puVar6 + 0x1a) = *(undefined2 *)(in_EAX + 0x24);
        *(int *)(in_EAX + 0x24) = *(int *)(in_EAX + 0x24) + 1;
        if (0xffffff < *(uint *)(in_EAX + 0x24)) {
          *(undefined4 *)(in_EAX + 0x24) = 0;
        }
        *(undefined2 *)(puVar6 + 7) = *(undefined2 *)(in_EAX + 0x28);
        puVar6[0x11] = param_2[0x11];
        *(undefined1 *)((int)puVar6 + 0x16) = 0x10;
        *(byte *)((int)puVar6 + 0x16) = *(byte *)((int)param_2 + 0x16) & 8 | 0x10;
        if (*(int *)(in_EAX + 0x2c) == 0) {
          puVar6[8] = (param_2[8] - (int)puVar6) + (int)param_2;
          puVar6[0x12] = 0xaaaaaaaa;
          puVar6[0x13] = 0xaaaaaaaa;
          puVar6[0x14] = 0xaaaaaaaa;
          puVar6[0x15] = 0xaaaaaaaa;
          puVar1 = (undefined4 *)(puVar6[8] + -0x10 + (int)puVar6);
          *puVar1 = 0xaaaaaaaa;
          puVar1[1] = 0xaaaaaaaa;
          puVar1[2] = 0xaaaaaaaa;
          puVar1[3] = 0xaaaaaaaa;
        }
        else {
          puVar6[8] = uVar5;
        }
        puVar6[0xc] = param_2;
        puVar6[0xd] = param_2[0xd];
        param_2[0xd] = puVar6;
        if (puVar6[0xd] == 0) {
          *(undefined4 **)(in_EAX + 0x60) = puVar6;
        }
        else {
          *(undefined4 **)(puVar6[0xd] + 0x30) = puVar6;
        }
        *(byte *)((int)param_2 + 0x16) = *(byte *)((int)param_2 + 0x16) | 8;
        if (*(int *)(in_EAX + 0x1c) == 0) {
          FUN_005d6b90();
        }
        else if (*(int *)(in_EAX + 0x1c) == 1) {
          FUN_005d6c20();
        }
        if (*(int *)(in_EAX + 0x2c) == 0) {
          param_2[8] = (int)local_4 - (int)param_2;
          param_2[0x12] = 0xaaaaaaaa;
          param_2[0x13] = 0xaaaaaaaa;
          param_2[0x14] = 0xaaaaaaaa;
          param_2[0x15] = 0xaaaaaaaa;
          puVar6 = (undefined4 *)(param_2[8] + -0x10 + (int)param_2);
          *puVar6 = 0xaaaaaaaa;
          puVar6[1] = 0xaaaaaaaa;
          puVar6[2] = 0xaaaaaaaa;
          puVar6[3] = 0xaaaaaaaa;
        }
        else {
          param_2[8] = puVar6[9] - param_2[9];
        }
        goto LAB_005d6f8b;
      }
    }
    else {
      uVar5 = ((param_2[9] - (int)param_3) - param_5) + param_2[8];
      if (0xf < uVar5) goto LAB_005d70fa;
      if (iVar4 == 0) goto LAB_005d70ee;
    }
  }
  *(int *)(in_EAX + 0x54) = *(int *)(in_EAX + 0x54) + -1;
LAB_005d6f8b:
  *(int *)(in_EAX + 0x58) = *(int *)(in_EAX + 0x58) - param_2[8];
  *(int *)(in_EAX + 0x68) = *(int *)(in_EAX + 0x68) + param_2[8];
  return local_c;
}

