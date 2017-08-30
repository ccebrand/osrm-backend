#ifndef OSMIUM_AREA_PROBLEM_REPORTER_EXCEPTION_HPP
#define OSMIUM_AREA_PROBLEM_REPORTER_EXCEPTION_HPP

/*

This file is part of Osmium (http://osmcode.org/libosmium).

Copyright 2013-2017 Jochen Topf <jochen@topf.org> and others (see README).

Boost Software License - Version 1.0 - August 17th, 2003

Permission is hereby granted, free of charge, to any person or organization
obtaining a copy of the software and accompanying documentation covered by
this license (the "Software") to use, reproduce, display, distribute,
execute, and transmit the Software, and to prepare derivative works of the
Software, and to permit third-parties to whom the Software is furnished to
do so, all subject to the following:

The copyright notices in the Software and this entire statement, including
the above license grant, this restriction and the following disclaimer,
must be included in all copies of the Software, in whole or in part, and
all derivative works of the Software, unless such copies or derivative
works are solely in the form of machine-executable object code generated by
a source language processor.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
DEALINGS IN THE SOFTWARE.

*/

#include <sstream>
#include <stdexcept>

#include <osmium/area/problem_reporter_stream.hpp>
#include <osmium/osm/location.hpp>
#include <osmium/osm/types.hpp>

namespace osmium {

    class NodeRef;
    class Way;

    namespace area {

        class ProblemReporterException : public ProblemReporterStream {

            std::stringstream m_sstream;

        public:

            ProblemReporterException() :
                ProblemReporterStream(m_sstream) {
            }

            ~ProblemReporterException() override = default;

            void report_duplicate_node(osmium::object_id_type node_id1, osmium::object_id_type node_id2, osmium::Location location) override {
                m_sstream.str("");
                ProblemReporterStream::report_duplicate_node(node_id1, node_id2, location);
                throw std::runtime_error{m_sstream.str()};
            }

            void report_touching_ring(osmium::object_id_type node_id, osmium::Location location) override {
                m_sstream.str("");
                ProblemReporterStream::report_touching_ring(node_id, location);
                throw std::runtime_error{m_sstream.str()};
            }

            void report_intersection(osmium::object_id_type way1_id, osmium::Location way1_seg_start, osmium::Location way1_seg_end,
                                     osmium::object_id_type way2_id, osmium::Location way2_seg_start, osmium::Location way2_seg_end, osmium::Location intersection) override {
                m_sstream.str("");
                ProblemReporterStream::report_intersection(way1_id, way1_seg_start, way1_seg_end, way2_id, way2_seg_start, way2_seg_end, intersection);
                throw std::runtime_error{m_sstream.str()};
            }

            void report_duplicate_segment(const osmium::NodeRef& nr1, const osmium::NodeRef& nr2) override {
                m_sstream.str("");
                ProblemReporterStream::report_duplicate_segment(nr1, nr2);
                throw std::runtime_error{m_sstream.str()};
            }

            void report_overlapping_segment(const osmium::NodeRef& nr1, const osmium::NodeRef& nr2) override {
                m_sstream.str("");
                ProblemReporterStream::report_overlapping_segment(nr1, nr2);
                throw std::runtime_error{m_sstream.str()};
            }

            void report_ring_not_closed(const osmium::NodeRef& nr, const osmium::Way* way = nullptr) override {
                m_sstream.str("");
                ProblemReporterStream::report_ring_not_closed(nr, way);
                throw std::runtime_error{m_sstream.str()};
            }

            void report_role_should_be_outer(osmium::object_id_type way_id, osmium::Location seg_start, osmium::Location seg_end) override {
                m_sstream.str("");
                ProblemReporterStream::report_role_should_be_outer(way_id, seg_start, seg_end);
                throw std::runtime_error{m_sstream.str()};
            }

            void report_role_should_be_inner(osmium::object_id_type way_id, osmium::Location seg_start, osmium::Location seg_end) override {
                m_sstream.str("");
                ProblemReporterStream::report_role_should_be_inner(way_id, seg_start, seg_end);
                throw std::runtime_error{m_sstream.str()};
            }

            void report_way_in_multiple_rings(const osmium::Way& way) override {
                m_sstream.str("");
                ProblemReporterStream::report_way_in_multiple_rings(way);
                throw std::runtime_error{m_sstream.str()};
            }

            void report_inner_with_same_tags(const osmium::Way& way) override {
                m_sstream.str("");
                ProblemReporterStream::report_inner_with_same_tags(way);
                throw std::runtime_error{m_sstream.str()};
            }

            void report_invalid_location(osmium::object_id_type way_id, osmium::object_id_type node_id) override {
                m_sstream.str("");
                ProblemReporterStream::report_invalid_location(way_id, node_id);
                throw std::runtime_error{m_sstream.str()};
            }

            void report_duplicate_way(const osmium::Way& way) override {
                m_sstream.str("");
                ProblemReporterStream::report_duplicate_way(way);
                throw std::runtime_error{m_sstream.str()};
            }

        }; // class ProblemReporterException

    } // namespace area

} // namespace osmium

#endif // OSMIUM_AREA_PROBLEM_REPORTER_EXCEPTION_HPP
