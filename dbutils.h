/*
 * dbutils.h
 * Copyright (c) 2ndQuadrant, 2010-2012
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef _REPMGR_DBUTILS_H_
#define _REPMGR_DBUTILS_H_

#include "strutil.h"

PGconn *establishDBConnection(const char *conninfo, const bool exit_on_error);
PGconn *establishDBConnectionByParams(const char *keywords[],
                                      const char *values[],
                                      const bool exit_on_error);
bool    is_standby(PGconn *conn);
bool    is_witness(PGconn *conn, char *schema, char *cluster, int node_id);
bool	is_pgup(PGconn *conn, int timeout);
char   *pg_version(PGconn *conn, char* major_version);
bool	guc_setted(PGconn *conn, const char *parameter, const char *op,
                   const char *value);
bool	guc_setted_typed(PGconn *conn, const char *parameter, const char *op,
                   const char *value, const char *datatype);
const char	 *get_cluster_size(PGconn *conn);
PGconn *getMasterConnection(PGconn *standby_conn, char *schema, char *cluster,
                            int *master_id, char *master_conninfo_out);

int wait_connection_availability(PGconn *conn, int timeout);
bool CancelQuery(PGconn *conn, int timeout);
#endif
